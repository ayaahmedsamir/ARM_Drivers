#include"../include/BIT_Math.h"
#include"../include/STD_Types.h"
#include"../include/MNVIC_Private.h"
#include"../include/MNVIC_interface.h"

uint8 Global_u8IPR=0;

void MNVIC_voidEnableInterrupt(uint8 u8PostCPY)
{
	uint8 pos=u8PostCPY%REG_DIV;
	uint8 index=u8PostCPY/REG_DIV;

	SET_BIT(NVIC->NVIC_ISER[index],pos);

}

void MNVIC_voidDisableInterrupt(uint8 u8PostCPY)
{
	uint8 pos=u8PostCPY%REG_DIV;
	uint8 index=u8PostCPY/REG_DIV;

	SET_BIT(NVIC->NVIC_ICER[index],pos);

}

void MNVIC_voidEnableInterruptPending(uint8 u8PostCPY)
{
	uint8 pos=u8PostCPY%REG_DIV;
	uint8 index=u8PostCPY/REG_DIV;

	SET_BIT(NVIC->NVIC_ISPR[index],pos);

}

void MNVIC_voidDisableInterruptPending(uint8 u8PostCPY)
{
	uint8 pos=u8PostCPY%REG_DIV;
	uint8 index=u8PostCPY/REG_DIV;

	SET_BIT(NVIC->NVIC_ICPR[index],pos);

}

void MNVIC_voidIsInterruptActive(uint8 u8PostCPY, uint8* Copy_Read)
{

	uint8 pos=u8PostCPY%REG_DIV;
	uint8 index=u8PostCPY/REG_DIV;

	*Copy_Read = GET_BIT(NVIC->NVIC_IABR[index],pos);

}

void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t enuGroupCPY)
{
	Global_u8IPR=enuGroupCPY;
	uint32 u32LocalCPY = NVIC_VECTKEY | (enuGroupCPY<<8) ;

	SCB_AIRCR=u32LocalCPY;

}

void MNVIC_voidSetInterruptPriority(uint8 u8PosCPY, uint8 u8GroupNumCPY,uint8 u8SubGroupNumCPY)
{

	switch(Global_u8IPR)
	{
	case GROUP_16_SUB_0:
		NVIC->NVIC_IPR[u8PosCPY]= u8GroupNumCPY << 4;
		break;
	case GROUP_8_SUB_2:
		NVIC->NVIC_IPR[u8PosCPY]= u8GroupNumCPY << 5 | u8SubGroupNumCPY << 4 ;
		break;
	case GROUP_4_SUB_4:
		NVIC->NVIC_IPR[u8PosCPY]= u8GroupNumCPY << 6 | u8SubGroupNumCPY << 4 ;
		break;
	case GROUP_2_SUB_8:
		NVIC->NVIC_IPR[u8PosCPY]= u8GroupNumCPY << 7 | u8SubGroupNumCPY << 4 ;
		break;
	case GROUP_0_SUB_16:
		NVIC->NVIC_IPR[u8PosCPY]= u8SubGroupNumCPY << 4 ;
		break;

	}
}


