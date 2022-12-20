#ifndef UART_INT_H
#define UART_INT_H

void UART_VidInt(void);

void UART_VidSendData(u8 Copy_u8Data);

u8 UART_u8RecieveData(void);

u32 kpd_Get_arrNum(u8 *arr, u8 size);

void UART_Vid_SendString(u8 *user);

void UART_Vid_SendInt(u32 Copy_U32Number);

#endif
