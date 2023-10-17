

#ifndef HTFT_INTERFACE_H_
#define HTFT_INTERFACE_H_

void HTFT_voidWriteCmd(uint8 u8CmdCPY);
void HTFT_voidWriteData(uint8 u8DataCPY);
void HTFT_voidReset(void);
void HTFT_voidInit(void);
void HTFT_voidDisplay(const uint16 * pu8Array);

#endif /* HTFT_INTERFACE_H_ */
