

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define BASE_ADDRESS     (0xE000E010)

/*******************************SYSTICK_ClockSourceOption************************************/
#define SYSTICK_AHB        1
#define SYSTICK_AHB_DIV_8  0
/************************************Delay_multiply******************************************/
#define MULTIPLY_16        16
#define MULTIPLY_2         2

typedef struct
{
	uint32 STK_CTRL;
	uint32 STK_LOAD;
	uint32 STK_VAL;
	uint32 STK_CALIB;

}SYSTICK_t;


#define SYSTICK           ((volatile SYSTICK_t*)BASE_ADDRESS)

/*****************************************CTRL_Reg_Bits************************************/
#define CTRL_EN               0
#define CTRL_INT              1
#define CTRL_CLOCK_SOURCE     2
#define CTRL_COUNT_FLAG       16

#endif /* SYSTICK_PRIVATE_H_ */
