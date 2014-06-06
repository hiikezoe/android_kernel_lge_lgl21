/* Copyright (c) 2011-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/mfd/pm8xxx/pm8921-bms.h>
#ifdef CONFIG_LGE_PM
/* LGE_S  2200mAh rbatt table from QCT */
#if 1//new rbatt from QCT 2012-08-14
static struct single_row_lut fcc_temp = {
	   .x			 = {-20, 0, 25, 40, 60},
	   .y			 = {2188, 2204, 2210, 2210, 2205},
	   .cols  = 5
};

static struct single_row_lut fcc_sf = {
	   .x			 = {0},
	   .y			 = {100},
	   .cols  = 1
};


static struct sf_lut rbatt_sf = {
		.rows			= 28,
		.cols			= 5,
		/* row_entries are temperature */
		.row_entries	= {-20, 0, 25, 40, 60},
		.percent		= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55,
		50, 45, 40, 35, 30, 25, 20, 15,
		10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
		.sf 			= {
					 {1426,293,100,86,89},
					 {1383,293,101,87,90},
					 {1329,297,103,88,91},
					 {1262,304,106,90,91},
					 {1209,308,109,92,93},
					 {1176,302,115,94,94},
					 {1164,283,126,100,97},
					 {1181,267,136,111,103},
					 {1210,263,104,89,92},
					 {1248,262,101,88,91},
					 {1288,263,102,88,91},
					 {1325,269,103,90,93},
					 {1378,285,103,93,96},
					 {1454,308,104,89,91},
					 {1571,329,104,88,91},
					 {1739,335,106,88,92},
					 {1987,385,107,89,92},
					 {2430,493,122,97,96},
					 {2282,459,125,98,97},
					 {2431,471,134,100,97},
					 {2808,485,141,102,104},
					 {3429,493,151,117,110},
					 {4363,519,159,123,116},
					 {5844,566,164,131,122},
					 {8340,656,173,140,129},
					 {12749,838,197,153,141},
					 {20616,1310,251,181,168},
					 {34171,3350,460,360,387},
	   }
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	   .rows		 = 29,
	   .cols		 = 5,
	   .temp		 = {-20, 0, 25, 40, 60},
	   .percent 	  = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
	   45, 40, 35, 30, 25, 20, 15,
	   10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	   .ocv 		 = {
					 {4330, 4328, 4324, 4319, 4312},
					 {4208, 4249, 4254, 4253, 4249},
					 {4125, 4189, 4196, 4195, 4191},
					 {4052, 4133, 4140, 4139, 4136},
					 {3981, 4079, 4087, 4086, 4083},
					 {3920, 4028, 4038, 4037, 4034},
					 {3870, 3975, 3992, 3991, 3989},
					 {3830, 3923, 3951, 3951, 3948},
					 {3804, 3879, 3907, 3910, 3908},
					 {3781, 3845, 3855, 3856, 3856},
					 {3755, 3817, 3826, 3828, 3828},
					 {3728, 3794, 3804, 3806, 3805},
					 {3697, 3777, 3787, 3789, 3787},
					 {3665, 3766, 3773, 3775, 3772},
					 {3634, 3752, 3763, 3758, 3748},
					 {3604, 3730, 3748, 3742, 3728},
					 {3570, 3695, 3723, 3718, 3704},
					 {3524, 3662, 3679, 3676, 3665},
					 {3458, 3606, 3654, 3659, 3650},
					 {3442, 3589, 3645, 3650, 3641},
					 {3422, 3565, 3630, 3635, 3623},
					 {3397, 3532, 3602, 3607, 3590},
					  {3369, 3488, 3560, 3567, 3548},
					  {3334, 3435, 3505, 3516, 3496},
					  {3287, 3372, 3440, 3452, 3432},
					  {3228, 3298, 3364, 3375, 3355},
					  {3153, 3212, 3276, 3282, 3256},
					  {3073, 3116, 3161, 3154, 3126},
					  {3000, 3000, 3000, 3000, 3000}
		}
};

struct pm8921_bms_battery_data LGE_2200_PMH_data/*LGE_PMH_LGU+_L20_data*/ = {
		.fcc						= 2200,
		.fcc_temp_lut		  = &fcc_temp,
		.fcc_sf_lut 				 = &fcc_sf,
		.pc_temp_ocv_lut	   = &pc_temp_ocv,
		.rbatt_sf_lut		  = &rbatt_sf,
		.default_rbatt_mohm    = 164,
};
#else

static struct single_row_lut lge_2200_fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {2147, 2166, 2181, 2184, 2207},
	.cols	= 5
};

static struct single_row_lut lge_2200_fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut lge_2200_rbatt_sf = {
	.rows           = 28,
	.cols           = 5,
	/* row_entries are temperature */
	.row_entries    = {-20, 0, 25, 40, 60},
	.percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
	                 45, 40, 35, 30, 25, 20, 15, 10,
	                 9, 8, 7, 6, 5, 4, 3, 2, 1},
	.sf             = {
		{551,222,100,88,108},
		{539,224,101,90,108},
		{523,223,103,91,109},
		{506,223,105,92,110},
		{496,221,108,94,111},
		{490,217,112,97,113},
		{487,210,115,101,115},
		{493,207,112,102,118},
		{503,206,101,91,109},
		{516,206,100,90,107},
		{532,211,101,91,109},
		{548,222,102,92,111},
		{569,237,104,92,113},
		{599,253,108,94,110},
		{641,269,112,95,110},
		{743,283,115,95,112},
		{1078,300,117,95,110},
		{2020,339,133,105,116},
		{1758,317,122,100,114},
		{1989,324,124,102,114},
		{2310,333,125,103,114},
		{2740,343,125,104,117},
		{3371,356,126,108,120},
		{4292,377,127,110,122},
		{5690,411,130,110,124},
		{7881,466,135,113,126},
		{11742,614,144,120,131},
		{17852,922,161,134,138},
	}
};

static struct pc_temp_ocv_lut lge_2200_pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
				45, 40, 35, 30, 25, 20, 15, 10,
				9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
		{4329, 4327, 4323, 4317, 4303},
		{4218, 4245, 4252, 4249, 4239},
		{4142, 4183, 4193, 4191, 4181},
		{4074, 4127, 4138, 4135, 4127},
		{4006, 4074, 4085, 4083, 4075},
		{3946, 4024, 4036, 4034, 4027},
		{3895, 3971, 3991, 3990, 3982},
		{3852, 3920, 3951, 3950, 3942},
		{3821, 3877, 3908, 3911, 3905},
		{3798, 3842, 3857, 3860, 3855},
		{3776, 3812, 3826, 3828, 3825},
		{3752, 3792, 3803, 3805, 3803},
		{3724, 3780, 3786, 3788, 3785},
		{3695, 3770, 3774, 3773, 3771},
		{3669, 3758, 3766, 3763, 3750},
		{3643, 3740, 3755, 3749, 3730},
		{3615, 3710, 3731, 3725, 3706},
		{3581, 3664, 3687, 3685, 3665},
		{3529, 3594, 3654, 3660, 3651},
		{3517, 3580, 3648, 3655, 3644},
		{3504, 3568, 3640, 3647, 3633},
		{3489, 3557, 3628, 3634, 3612},
		{3470, 3541, 3603, 3609, 3581},
		{3446, 3514, 3563, 3572, 3542},
		{3418, 3473, 3511, 3523, 3494},
		{3383, 3422, 3450, 3461, 3436},
		{3339, 3361, 3380, 3388, 3369},
		{3280, 3287, 3300, 3305, 3294},
		{3200, 3200, 3200, 3200, 3200}
	}
};

static struct sf_lut lge_2200_pc_sf = {
	.rows		 = 1,
	.cols		 = 1,
	.row_entries = {0},
	.percent	 = {100},
	.sf			 = {
		{100}
	}
};

struct pm8921_bms_battery_data LGE_2200_PMH_data = {
	.fcc				= 2200,
	.fcc_temp_lut		= &lge_2200_fcc_temp,
	.fcc_sf_lut			= &lge_2200_fcc_sf,
	.pc_temp_ocv_lut	= &lge_2200_pc_temp_ocv,
	.pc_sf_lut			= &lge_2200_pc_sf,
	.rbatt_sf_lut		= &lge_2200_rbatt_sf,
	.default_rbatt_mohm	= 165,
};
#endif
/* LGE_E  2200mAh rbatt table from QCT */

/* LGE_S  2100mAh rbatt table from QCT */
//receive from 2012_08_09
static struct single_row_lut lge_2100_fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
#if CONFIG_LGE_PM
	.y		= {2068, 2064, 2103, 2072, 2084},
#else
	.y		= {2101, 2101, 2099, 2096, 2092, 2083},
#endif
	.cols	= 5
};

static struct single_row_lut lge_2100_fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut lge_2100_rbatt_sf = {
        .rows           = 28,
        .cols           = 5,
        /* row_entries are temperature */
        .row_entries            = {-20, 0, 25, 40, 60},
        .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        .sf                     = {
          {639,265,100,75,66},
          {700,262,104,79,68},
          {727,259,106,81,70},
          {746,258,106,82,72},
          {764,260,106,83,74},
          {785,263,106,84,74},
          {818,268,100,84,75},
          {855,272,99,83,74},
          {901,275,100,76,68},
          {955,280,103,78,69},
          {1016,287,107,80,71},
          {1080,297,112,83,73},
          {1147,309,116,87,75},
          {1221,324,120,90,73},
          {1308,345,124,90,72},
          {1436,397,125,89,73},
          {1673,500,128,87,70},
          {2288,587,156,102,78},
          {1681,361,140,94,75},
          {1886,368,145,95,75},
          {2140,377,148,94,73},
          {2462,388,151,93,73},
          {2877,412,160,96,74},
          {3422,473,174,99,77},
          {4273,562,195,105,81},
          {5469,719,228,112,84},
          {8749,1722,274,120,93},
          {20487,18766,897,170,1139},
	 }
};

static struct pc_temp_ocv_lut lge_2100_pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4331, 4325, 4327, 4317, 4315},
				{4237, 4252, 4261, 4253, 4253},
				{4163, 4190, 4202, 4195, 4196},
				{4091, 4132, 4147, 4140, 4141},
				{4034, 4074, 4093, 4088, 4088},
				{3990, 4017, 4043, 4039, 4039},
				{3952, 3964, 3992, 3993, 3993},
				{3920, 3923, 3937, 3953, 3952},
				{3890, 3887, 3895, 3913, 3914},
				{3863, 3854, 3860, 3864, 3865},
				{3839, 3825, 3831, 3832, 3833},
				{3815, 3804, 3809, 3808, 3809},
				{3794, 3786, 3791, 3789, 3790},
				{3775, 3772, 3775, 3774, 3774},
				{3757, 3758, 3764, 3763, 3755},
				{3739, 3741, 3750, 3747, 3735},
				{3720, 3724, 3725, 3721, 3710},
				{3694, 3707, 3689, 3686, 3673},
				{3654, 3684, 3674, 3669, 3659},
				{3645, 3679, 3670, 3667, 3657},
				{3635, 3673, 3664, 3663, 3653},
				{3620, 3662, 3648, 3655, 3640},
				{3601, 3643, 3612, 3631, 3611},
				{3575, 3611, 3563, 3591, 3570},
				{3538, 3562, 3501, 3540, 3521},
				{3484, 3495, 3430, 3480, 3460},
				{3405, 3403, 3347, 3401, 3377},
				{3284, 3276, 3223, 3280, 3244},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut lge_2100_pc_sf = {
	.rows		= 1,
	.cols		= 1,
	.percent	= {100},
	.sf			= {
				{100}
	}
};
struct pm8921_bms_battery_data LGE_2100_PMH_data = {
	.fcc				  = 2100,
	.fcc_temp_lut		  = &lge_2100_fcc_temp,
	.fcc_sf_lut			  = &lge_2100_fcc_sf,
	.pc_temp_ocv_lut	  = &lge_2100_pc_temp_ocv,
	.pc_sf_lut			  = &lge_2100_pc_sf,
	.rbatt_sf_lut		  = &lge_2100_rbatt_sf,
	.default_rbatt_mohm	  = 182, //206, //106,
};
/* LGE_E  2100mAh rbatt table from QCT */

/* LGE_S  1900mAh rbatt table from QCT */
static struct single_row_lut lge_1840_fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {1834, 1854, 1869, 1872, 1868},
	.cols	= 5
};

static struct single_row_lut lge_1840_fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut lge_1840_rbatt_sf = {
    .rows           = 28,
    .cols           = 5,
    /* row_entries are temperature */
    .row_entries    = {-20, 0, 25, 40, 60},
    .percent        = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
    		45, 40, 35, 30, 25, 20, 15, 10,
    		9, 8, 7, 6, 5, 4, 3, 2, 1},
    .sf             = {
			{957,310,100,73,53},
			{969,316,104,76,54},
			{972,320,109,79,57},
			{974,322,113,81,59},
			{978,321,117,84,62},
			{987,320,119,87,64},
			{996,322,116,88,67},
			{1007,324,107,83,68},
			{1022,326,107,75,58},
			{1041,330,107,74,55},
			{1068,333,109,75,56},
			{1105,340,112,77,57},
			{1182,349,114,80,60},
			{1305,361,116,82,63},
			{1475,374,117,79,56},
			{1712,390,115,75,56},
			{2072,412,117,77,58},
			{2827,459,120,79,58},
			{1270,354,105,71,54},
			{1391,361,105,71,54},
			{1551,373,106,73,55},
			{1787,392,109,75,57},
			{2136,416,112,77,58},
			{2670,453,116,79,59},
			{3562,499,120,79,59},
			{5175,577,124,80,59},
			{8317,730,131,83,60},
			{14927,1208,144,90,65},
	}
};


static struct pc_temp_ocv_lut lge_1840_pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
				45, 40, 35, 30, 25, 20, 15, 10,
				9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4328, 4326, 4322, 4316, 4308},
				{4220, 4239, 4242, 4240, 4236},
				{4150, 4179, 4184, 4183, 4179},
				{4089, 4122, 4131, 4129, 4127},
				{4031, 4068, 4080, 4079, 4077},
				{3978, 4014, 4033, 4032, 4031},
				{3931, 3965, 3988, 3989, 3988},
				{3890, 3923, 3943, 3948, 3949},
				{3854, 3886, 3899, 3906, 3911},
				{3823, 3853, 3865, 3867, 3867},
				{3798, 3826, 3837, 3838, 3836},
				{3776, 3802, 3814, 3815, 3813},
				{3756, 3785, 3795, 3797, 3795},
				{3737, 3771, 3780, 3782, 3780},
				{3719, 3761, 3768, 3767, 3763},
				{3701, 3749, 3754, 3748, 3735},
				{3683, 3733, 3736, 3727, 3713},
				{3661, 3706, 3711, 3704, 3691},
				{3631, 3668, 3676, 3672, 3659},
				{3626, 3660, 3669, 3667, 3656},
				{3618, 3650, 3664, 3663, 3653},
				{3608, 3640, 3659, 3660, 3649},
				{3594, 3629, 3652, 3654, 3644},
				{3578, 3617, 3642, 3645, 3634},
				{3559, 3599, 3625, 3626, 3615},
				{3533, 3574, 3593, 3592, 3580},
				{3500, 3534, 3546, 3544, 3532},
				{3457, 3477, 3482, 3481, 3474},
				{3400, 3400, 3400, 3400, 3400}
	}
};

static struct sf_lut lge_1840_pc_sf = {
	.rows		= 1,
	.cols		= 1,
	.row_entries	= {0},
	.percent	= {100},
	.sf			= {
				{100}
	}
};

struct pm8921_bms_battery_data lge_1840_data = {
	.fcc				= 1840,
	.fcc_temp_lut		= &lge_1840_fcc_temp,
	.fcc_sf_lut			= &lge_1840_fcc_sf,
	.pc_temp_ocv_lut	= &lge_1840_pc_temp_ocv,
	.pc_sf_lut			= &lge_1840_pc_sf,
	.rbatt_sf_lut		= &lge_1840_rbatt_sf,
	.default_rbatt_mohm	= 111,
};
/* LGE_S  1900mAh rbatt table from QCT QCT*/
#endif

/* LGE_S  1900mAh table from LG-Chemistry*/
static struct single_row_lut lge_1900_fcc_temp = {
	.x	= {-20, 0, 25, 40, 65},
	.y	= {1899, 1899, 1900, 1890, 1909},
	.cols	= 5,
};

static struct single_row_lut lge_1900_fcc_sf = {
	.x	= {100, 200, 300, 400, 500},
	.y	= {98, 95, 93, 89, 85},
	.cols	= 5,
};

static struct sf_lut lge_1900_pc_sf = {
	.rows		= 10,
	.cols		= 5,
	.row_entries	= {100, 200, 300, 400, 500},
	.percent	= {100, 90, 80, 70, 60, 50, 40, 30, 20, 10},
	.sf		= {
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{100, 100, 100, 100, 100},
			{99, 99, 99, 99, 99},
			{99, 99, 99, 99, 99}
	},
};

static struct pc_temp_ocv_lut  lge_1900_pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55,
				50, 45, 40, 35, 30, 25, 20, 15, 10, 9,
				8, 7, 6, 5, 4, 3, 2, 1, 0
	},
	.ocv		= {
			{4302, 4296, 4292, 4285, 4283},
			{4208, 4211, 4212, 4206, 4208},
			{4139, 4154, 4151, 4143, 4142},
			{4046, 4082, 4092, 4089, 4093},
			{3986, 4013, 4035, 4036, 4037},
			{3926, 3955, 3981, 3977, 3977},
			{3867, 3894, 3924, 3920, 3919},
			{3814, 3843, 3875, 3871, 3869},
			{3792, 3821, 3833, 3836, 3842},
			{3764, 3788, 3795, 3793, 3792},
			{3739, 3758, 3763, 3763, 3762},
			{3715, 3734, 3737, 3735, 3735},
			{3691, 3713, 3712, 3709, 3710},
			{3668, 3693, 3692, 3687, 3686},
			{3644, 3671, 3674, 3668, 3654},
			{3624, 3648, 3655, 3646, 3628},
			{3612, 3616, 3632, 3622, 3604},
			{3596, 3598, 3591, 3584, 3563},
			{3546, 3566, 3553, 3546, 3533},
			{3535, 3556, 3545, 3538, 3526},
			{3516, 3541, 3534, 3527, 3511},
			{3496, 3527, 3523, 3516, 3488},
			{3475, 3511, 3509, 3497, 3448},
			{3459, 3496, 3489, 3469, 3409},
			{3442, 3469, 3458, 3434, 3363},
			{3406, 3421, 3410, 3385, 3298},
			{3339, 3350, 3341, 3311, 3206},
			{3234, 3254, 3246, 3203, 3078},
			{3000, 3000, 3000, 3000, 3000}
	},
};

/* LGE_S  On LG-Chemistry added  1900mAh rbatt table QCT*/
static struct sf_lut lge_1900_rbatt_sf = {
	.rows		= 19,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 20, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50,
				45, 40, 35, 30, 25, 20, 15, 10
	},
	.sf		= {
				{645, 301, 100, 80, 69},
				{616, 290, 100, 79, 69},
				{586, 279, 100, 78, 68},
				{564, 270, 100, 78, 68},
				{546, 262, 100, 78, 68},
				{537, 256, 100, 79, 68},
				{536, 253, 100, 79, 69},
				{552, 258, 100, 81, 71},
				{618, 284, 100, 80, 72},
				{643, 290, 100, 77, 68},
				{673, 294, 100, 77, 68},
				{720, 296, 100, 77, 69},
				{769, 294, 100, 76, 68},
				{821, 288, 100, 74, 67},
				{892, 284, 100, 74, 61},
				{1003, 290, 100, 71, 58},
				{1192, 307, 100, 70, 58},
				{1579, 345, 100, 68, 57},
				{1261, 324, 100, 68, 57},
	}
};
/* LGE_E  On LG-Chemistry added  1900mAh rbatt table QCT*/

struct pm8921_bms_battery_data  lge_1900_data = {
	.fcc                = 1900,
	.fcc_temp_lut       = &lge_1900_fcc_temp,
	.fcc_sf_lut         = &lge_1900_fcc_sf,
	.pc_temp_ocv_lut    = &lge_1900_pc_temp_ocv,
	.pc_sf_lut          = &lge_1900_pc_sf,
/* LGE_S  On LG-Chemistry added  1900mAh rbatt table QCT*/
	.rbatt_sf_lut       = &lge_1900_rbatt_sf,
	.default_rbatt_mohm	= 200,
/* LGE_E  On LG-Chemistry added  1900mAh rbatt table QCT*/
};
/* LGE_S  1900mAh table from LG-Chemistry*/