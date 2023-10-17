#include"../include/BIT_Math.h"
#include"../include/STD_Types.h"
#include"../include/HTFT_private.h"
#include"../include/HTFT_interface.h"
#include"../include/HTFT_Config.h"
#include"../include/MGPIO_interface.h"
#include"../include/MGPIO_Private.h"
#include"STK_interface.h"
#include"MSPI_interface.h"

void HTFT_voidWriteCmd(uint8 u8CmdCPY)
{
	MGPIO_writePin(A0_PORT,A0_PIN,LOW);
	MPSI_u8SendData(u8CmdCPY);
}

void HTFT_voidWriteData(uint8 u8DataCPY)
{
	MGPIO_writePin(A0_PORT,A0_PIN,HIGH);
	MPSI_u8SendData(u8DataCPY);
}

void HTFT_voidReset(void)
{

	MGPIO_writePin(RESET_PORT,RESET_PIN,HIGH);
	MSYSTICK_voidDelayMs(100);
	MGPIO_writePin(RESET_PORT,RESET_PIN,LOW);
	MSYSTICK_voidDelayMs(1);
	MGPIO_writePin(RESET_PORT,RESET_PIN,HIGH);
	MSYSTICK_voidDelayMs(100);
	MGPIO_writePin(RESET_PORT,RESET_PIN,LOW);
	MSYSTICK_voidDelayMs(100);
	MGPIO_writePin(RESET_PORT,RESET_PIN,HIGH);
	MSYSTICK_voidDelayms(120);

}

void HTFT_voidInit(void)
{
	HTFT_voidReset();
	HTFT_voidWriteCmd(0x11);
	MSYSTICK_voidDelayms(150);
	HTFT_voidWriteCmd(0x3A);
	HTFT_voidWriteData(0x05);
	HTFT_voidWriteCmd(0x29);
	MSYSTICK_voidDelayms(1);
}

void HTFT_voidDisplay(const uint16 * pu8Array)
{
	uint8 u8High=0;
	uint8 u8Low=0;
	HTFT_voidWriteCmd(0x2A);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);
	HTFT_voidWriteCmd(0x2B);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);
	HTFT_voidWriteCmd(0x2C);


	for(int i=0;i<20480;i++)
	{
		u8Low= (uint8) (pu8Array[i]);
		u8High=(uint8) (pu8Array[i]>>8);

		HTFT_voidWriteData(u8High);
		HTFT_voidWriteData(u8Low);

	}

}





