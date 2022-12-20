/********************************************************************/
/****************    SWC : DIO Driver      **************************/
/****************    By  : AlaaSaeed       **************************/
/****************    Date: 27Aug           **************************/
/****************    Version : v1.0        **************************/
/********************************************************************/

#ifndef DIO_INT_H
#define DIO_INT_H

typedef enum{
	
	Port_A ,
	Port_B ,
	Port_C ,
	Port_D 
	
	
}et_port;

typedef enum{
	
	pin0 ,
	pin1 ,
	pin2 ,
	pin3 ,
	pin4 ,
	pin5 ,
	pin6 ,
	pin7 
	
}et_pin;

typedef enum{
	
	input,
	output
	
}et_Direction;


typedef enum{
	
	PinLow,
	PinHigh
	
}et_Status;

/*Setting pin Direction*/
void DIO_Vid_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*Setting pin value*/
void DIO_Vid_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*Getting pin value*/
void DIO_Vid_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *pu8Data);



/*Setting port Direction*/
void DIO_Vid_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/*Setting pin value*/
void DIO_Vid_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/*Getting pin value*/
void DIO_Vid_GetPportValue(u8 Copy_u8Port, u8 *pu8Data);



/*Setting pin Direction*/

/*Setting pin value*/

/*Getting pin direction*/

#endif