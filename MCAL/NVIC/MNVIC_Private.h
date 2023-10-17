
#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS    (0xE000E100)

#define REG_DIV                32


typedef struct
{
	uint32 NVIC_ISER[8];
	uint32 Reserved1[24];
	uint32 NVIC_ICER[8];
	uint32 Reserved2[24];
	uint32 NVIC_ISPR[8];
	uint32 Reserved3[24];
	uint32 NVIC_ICPR[8];
	uint32 Reserved4[24];
	uint32 NVIC_IABR[8];
	uint32 Reserved5[56];
	uint8 NVIC_IPR[240];
	uint32 Reserved6[580];
	uint32 NVIC_STIR;

}NVIC_t;

#define NVIC ((volatile NVIC_t*) NVIC_BASE_ADDRESS)

/**************************************For SCB ************************************************************************/
#define SCB_AIRCR         (*(volatile uint32*)0xE000ED0C)
#define NVIC_VECTKEY           (0x05FA0000)


#endif /* MNVIC_PRIVATE_H_ */
