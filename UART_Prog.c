#include "STD_Types.h"
#include "BIT_Math.h"
#include "UART_Private.h"

void UART_VidInt(void){
	UCSRC = (1<<7) | (3<<1);
	UBRRL = 51;
	Set(UCSRB, TXEN);
	Set(UCSRB, RXEN);
}

void UART_VidSendData(u8 Copy_u8Data){
	while(GetBit(UCSRA, UDRE)!=1);
	UDR = Copy_u8Data;
}

u8 UART_u8RecieveData(void){
	while(GetBit(UCSRA, RXC)!=1);
	return UDR;
}


// to convert the array elements into one number
u32 kpd_Get_arrNum(u8 *arr, u8 size){

	u32 val = 0;
	u32 number = 0;
	u32 n = 0 ;

	for(n = 0 ; n<size ; n++){

		number = arr[n] - '0';
		val = (val*10) + number;
	}

	return val;
}


void UART_Vid_SendString(u8 *user)
{
	u8 i = 0;
	UART_VidSendData(user[i]);
	while(user[i] != '\0')
	{
		i++;
		UART_VidSendData(user[i]);
	}
}



void UART_Vid_SendInt(u32 Copy_U32Number)
{
	if(Copy_U32Number != 0)
	{
		UART_Vid_SendInt(Copy_U32Number/10);
		UART_VidSendData((Copy_U32Number%10)+'0');
	}
}

