/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Aya ahmed samir        ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : STK                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 12 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include"BIT_Math.h"
#include"STD_Types.h"
#include"STK_private.h"
#include"STK_interface.h"
#include"STK_config.h"




void STK_voidInit (void)
{
	/* Initialize the configuration of the interrupt and prescaler */
	CTRL = ((INTERRUPT << CTRL_TICKINT) | (PRESCALER << CTRL_CLKSOURCE));
}

void STK_voidStart (void)
{
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidStop (void)
{
	/* Stop SysTick Timer */
	CLR_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidGetFlag (uint8 *Pointer_uint8Value)
{
	/* Get the flag value */
	*Pointer_uint8Value = GET_BIT(CTRL, CTRL_COUNTFLAG);
}

void STK_voidSetLoadValue (uint32 Copy_uint32Ticks)
{
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_uint32Ticks;
	VAL = 0;

}




void SYSTICK_voidDelayUs (uint32 Copy_uint32MicroSeconds)
{
	/* This is only for 16 MHz Clock */
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_uint32MicroSeconds * CLK_FREQ;
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
	/* Stop SysTick Timer */
	CLR_BIT(CTRL, CTRL_ENABLE);
}

void SYSTICK_voidDelayMs (uint32 Copy_uint32MilliSeconds)
{
	/* This is only for 16 MHz Clock */
	/* Load the Ticks in its register and make sure the VAL register will start from beginning */
	LOAD = Copy_uint32MilliSeconds * (CLK_FREQ * 1E3);
	VAL = 0;
	/* Start SysTick Timer */
	SET_BIT(CTRL, CTRL_ENABLE);
	/* Polling in the Flag */
	while (!GET_BIT(CTRL, CTRL_COUNTFLAG));
	/* Stop SysTick Timer */
	CLR_BIT(CTRL, CTRL_ENABLE);
}

void STK_voidGetRemainingTime (uint32 *Pointer_uint32MicroSecondsBuffer)
{
	/* Calculate the elapsed ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_uint32MicroSecondsBuffer = VAL / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_uint32MicroSecondsBuffer = VAL / (CLK_FREQ / DIV_BY_8);
	#endif
}

void STK_voidGetElapsedTime (uint32 *Pointer_uint32MicroSecondsBuffer)
{
	/* Calculate the remaining ticks */
	#if CLK_AHB == PRESCALER
		*Pointer_uint32MicroSecondsBuffer = (LOAD - VAL) / CLK_FREQ;
	#elif CLK_AHB_BY_8 == PRSCALER
		*Pointer_uint32MicroSecondsBuffer = (LOAD - VAL) / (CLK_FREQ / DIV_BY_8);
	#endif
}



