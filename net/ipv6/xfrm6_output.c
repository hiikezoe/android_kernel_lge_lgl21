/*
 * xfrm6_output.c - Common IPsec encapsulation code for IPv6.
 * Copyright (C) 2002 USAGI/WIDE Project
 * Copyright (c) 2004 Herbert Xu <herbert@gondor.apana.org.au>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#include <linux/if_ether.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/icmpv6.h>
#include <linux/netfilter_ipv6.h>
#include <net/dst.h>
#include <net/ipv6.h>
#include <net/ip6_route.h>
#include <net/xfrm.h>

int xfrm6_find_1stfragopt(struct xfrm_state *x, struct sk_buff *skb,
			  u8 **prevhdr)
{
	return ip6_find_1stfragopt(skb, prevhdr);
}

EXPORT_SYMBOL(xfrm6_find_1stfragopt);

static int xfrm6_tunnel_check_size(struct sk_buff *skb)
{
	int mtu, ret = 0;
	struct dst_entry *dst = skb_dst(skb);

	mtu = dst_mtu(dst);
	if (mtu < IPV6_MIN_MTU)
		mtu = IPV6_MIN_MTU;

	if (!skb->local_df && skb->len > mtu) {
		skb->dev = dst->dev;
		icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
		ret = -EMSGSIZE;
	}

	return ret;
}

int xfrm6_extract_output(struct xfrm_state *x, struct sk_buff *skb)
{
	int err;

	err = xfrm6_tunnel_check_size(skb);
	if (err)
		return err;

	XFRM_MODE_SKB_CB(skb)->protocol = ipv6_hdr(skb)->nexthdr;

	return xfrm6_extract_header(skb);
}

int xfrm6_prepare_output(struct xfrm_state *x, struct sk_buff *skb)
{
	int err;

	err = xfrm_inner_extract_output(x, skb);
	if (err)
		return err;

	memset(IP6CB(skb), 0, sizeof(*IP6CB(skb)));
#ifdef CONFIG_NETFILTER
	IP6CB(skb)->flags |= IP6SKB_XFRM_TRANSFORMED;
#endif

	skb->protocol = htons(ETH_P_IPV6);
	skb->local_df = 1;

	return x->outer_mode->output2(x, skb);
}
EXPORT_SYMBOL(xfrm6_prepare_output);

int xfrm6_output_finish(struct sk_buff *skb)
{
#ifdef CONFIG_NETFILTER
	IP6CB(skb)->flags |= IP6SKB_XFRM_TRANSFORMED;
#endif

	skb->protocol = htons(ETH_P_IPV6);
	return xfrm_output(skb);
}

static int __xfrm6_output(struct sk_buff *skb)
{
	struct dst_entry *dst = skb_dst(skb);
	struct xfrm_state *x = dst->xfrm;

	//start : sandeep.ankolekar@lge.com  7/19/12 368957
	/*Desc	: In case if x is NULL, it is being dereferenced, in both the cases
	**	  where it is returning, since in both returns same function is being called
	** 	  and in fail case they are returning negetive values, even here if x fails
	**	  -1 is returned
	*/
	if(!x){
		return -1;
	}
	//end : sandeep.ankolear@lge.com 7/19/12  368957	
	if ((x && x->props.mode == XFRM_MODE_TUNNEL) &&
	    ((skb->len > ip6_skb_dst_mtu(skb) && !skb_is_gso(skb)) ||
		dst_allfrag(skb_dst(skb)))) {
			return ip6_fragment(skb, x->outer_mode->afinfo->output_finish);
	}
	return x->outer_mode->afinfo->output_finish(skb);
}

int xfrm6_output(struct sk_buff *skb)
{
	return NF_HOOK(NFPROTO_IPV6, NF_INET_POST_ROUTING, skb, NULL,
		       skb_dst(skb)->dev, __xfrm6_output);
}
