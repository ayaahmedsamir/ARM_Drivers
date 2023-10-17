
#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


typedef enum
{
	GROUP_16_SUB_0=3, GROUP_8_SUB_2, GROUP_4_SUB_4, GROUP_2_SUB_8, GROUP_0_SUB_16
}MNVIC_GROUP_t;

void MNVIC_voidEnableInterrupt(uint8 u8PostCPY);
void MNVIC_voidDisableInterrupt(uint8 u8PostCPY);
void MNVIC_voidEnableInterruptPending(uint8 u8PostCPY); // for Testing //
void MNVIC_voidDisableInterruptPending(uint8 u8PostCPY); //For Testing //
void MNVIC_voidIsInterruptActive(uint8 u8PostCPY, uint8* Copy_Read);
void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t enuGroupCPY);
void MNVIC_voidSetInterruptPriority(uint8 u8PosCPY, uint8 u8GroupNumCPY,uint8 u8SubGroupNumCPY);

#endif /* MNVIC_INTERFACE_H_ */
