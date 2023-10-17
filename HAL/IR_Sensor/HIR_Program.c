#include"../include/BIT_Math.h"
#include"../include/STD_Types.h"
#include"../include/HIR_interface.h"
#include"SYSTICK_interface.h"

uint8 u8flag=0;
uint32 arr[32]={0};
uint8 u8counter={0};
uint8 u8data=0;
void func1 (void)
{
	if(u8flag==0)
	{
		u8flag=1;
		MSYSTICK_voidReloadValue(30000);
	}
	else
	{
		arr[u8counter]=MSISTICK_u32ElapsedTime();
		MSYSTICK_voidReloadValue(30000);
		u8counter++;

	}
}

void func2(void)
{
	u8flag=0;
	u8counter=0;
	uint8 u8i;
	for(u8i=0;u8i<8;u8i++)
	{
		if( (arr[25-u8i]>=1000) && (arr[25-u8i]<=1500) )
			CLR_BIT(u8data,u8i);

		else if ((arr[25-u8i]>=2000) && (arr[25-u8i]<=2500))
			SET_BIT(u8data,u8i);
	}

}

