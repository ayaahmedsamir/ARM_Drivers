
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

typedef enum
{
	Disable_int,Enable_int
}MSYSTICKState;

void MSYSTICK_voidInit(void);
void MSYSTICK_voidReloadValue(uint32 u32LoadValueCPY);
void MSYSTICK_voidDelayMs(uint32 u32DelayValue);
void MSYSTICK_voidDelayms(uint32 u32DelayValue);
uint8 MSYSTICK_voidReadFlag(void);
void MSYSTICK_voidCtrlIntState(MSYSTICKState StateCPY);
uint32 MSISTICK_u32RemainingTime(void);
uint32 MSISTICK_u32ElapsedTime(void);





#endif /* SYSTICK_INTERFACE_H_ */
