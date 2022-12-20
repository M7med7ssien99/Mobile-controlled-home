/*
 * main.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Omar Saeed
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "UART_Int.h"
#include "IMT_PROJECT_int.h"
#include <util/delay.h>


u8 z,b;
u8 check_name[10] = {0};//array that used to receive the user name from the user
u8 check_pass[10] = {0};//array that used to receive the pass from the user


int main()
{

	//TX
	DIO_Vid_SetPinDirection(Port_D,pin0,input);

	//RX
	DIO_Vid_SetPinDirection(Port_D,pin1,output);

	//LCD PORTS
	DIO_Vid_SetPortDirection(Port_C,output);
	DIO_Vid_SetPortDirection(Port_B,output);

	//LEDS PORT
	DIO_Vid_SetPortDirection(Port_A,output);

	//INITIALIZATION
	LCD_Vid_Init();
	UART_VidInt();

	LCD_vid_DisplayClear();
	UART_Vid_SendString("W E L C O M E !\n");
	LCD_vid_SendString("W E L C O M E !");

	_delay_ms(2000);

	while(1)
	{

		LCD_vid_DisplayClear();
		UART_Vid_SendString("enter U_Name :  ");
		LCD_vid_SendString("enter U_Name : ");
		UART_Vid_RecieveUserName(check_name);
		u8 x = Check_User(check_name);

		if(x == wrong_name)//Means their is no user name like you entered
		{

			LCD_vid_DisplayClear();
			UART_Vid_SendString("\n wrong name \n");
			LCD_vid_SendString("wrong name");
			_delay_ms(2000);

		}//end of  if condition (name)

		else if(x != wrong_name)//Means that you have entered a correct user name
		{

			LCD_vid_DisplayClear();
			UART_Vid_SendString("\n enter pass :  ");
			LCD_vid_SendString("enter pass : ");
			UART_Vid_RecievePass(check_pass);
			u8 y = Check_Pass(check_pass, x);

			if(y == wrong_pass)//Means that you have entered a wrong pass
			{//start of if condition (pass)
				z = 3;
				LCD_vid_DisplayClear();
				UART_Vid_SendString("\n try again..\n");

				LCD_vid_SendString("try again..");
				_delay_ms(2000);
				LCD_vid_DisplayClear();

				while(z > 0)//loop to re_enter the pass only 3 times
				{

					LCD_vid_DisplayClear();

					UART_Vid_SendString("\n you have ");
					UART_Vid_SendInt(z);

					LCD_vid_SendString("you have");
					LCD_vid_GoToX(1,0);
					LCD_vid_SendInt(z);

					UART_Vid_SendString(" attempts \n ");
					LCD_vid_SendString(" attempts ");
					_delay_ms(2000);
					LCD_vid_DisplayClear();
					UART_Vid_SendString("re-enter pass :  ");
					LCD_vid_SendString("re-enter pass : ");

					z--;

					UART_Vid_RecievePass(check_pass);
					b = Check_Pass(check_pass, x);

					if(b == wrong_pass)//Means that you have entered a wrong pass again
					{

						if(z == 0)
						{
							//buzzer on as you enter pass 3 times wrong
							DIO_Vid_SetPinValue(Port_B,pin3,PinHigh);
							_delay_ms(3000);
							DIO_Vid_SetPinValue(Port_B,pin3,PinLow);
						}

					}

					else
					{//Means that you have entered a correct pass

						break;//out of while loop (re_enter the pass)
					}

				}// end of while loop to re_enter the pass

			}//end of if condition (pass)

			if(y != wrong_pass || b != wrong_pass)//means pass is correct at the first time or at any time of the 3 attempts
			{

				u8 flag = 0;//set to exist
				DIO_Vid_SetPinValue(Port_B, pin4, PinHigh);//solenoid on
				LCD_vid_DisplayClear();
				 UART_Vid_SendString("\n welcome!   ");
				LCD_vid_SendString("welcome! ");
				LCD_vid_GoToX(1,0);
				UART_Vid_SendString(check_name);
				LCD_vid_SendString(check_name);
				_delay_ms(2000);
				LCD_vid_DisplayClear();
				DIO_Vid_SetPinValue(Port_B, pin4, PinLow);//solenoid off
				while(flag == 0)
				{//while loop ( operations )

					LCD_vid_DisplayClear();
					 UART_Vid_SendString("\n select : \n");
					LCD_vid_SendString("select :");

					LCD_vid_GoToX(1,0);
					UART_Vid_SendString("[a]>>to low light ");
					LCD_vid_SendString("a>>to low light");
					_delay_ms(2000);
					LCD_vid_GoToX(1,0);
					LCD_vid_SendString("                ");

					LCD_vid_GoToX(1,0);
					UART_Vid_SendString("[b]>>to high light \n");
					LCD_vid_SendString("b>>to high light");
					_delay_ms(2000);
					LCD_vid_GoToX(1,0);
					LCD_vid_SendString("                ");

					LCD_vid_GoToX(1,0);
					UART_Vid_SendString("[c]>>to fan on ");
					LCD_vid_SendString("c>>to fan on");
					_delay_ms(2000);
					LCD_vid_GoToX(1,0);
					LCD_vid_SendString("                ");

					LCD_vid_GoToX(1,0);
					UART_Vid_SendString("[d]>>to L/F off \n");
					LCD_vid_SendString("d>>to L/F off");
					_delay_ms(2000);
					LCD_vid_GoToX(1,0);
					LCD_vid_SendString("                ");

					LCD_vid_GoToX(1,0);
					UART_Vid_SendString("[e]>>to exit \n");
					LCD_vid_SendString("e>>to exit");
					_delay_ms(2000);
					LCD_vid_GoToX(1,0);
					LCD_vid_SendString("                ");

					u8 select = UART_u8RecieveData();//Receive the choice
					UART_VidSendData('\n');
					UART_VidSendData(select);
					LCD_vid_GoToX(1,0);

					switch(select)
					{//switch condition (operation)

						case 'a':

							DIO_Vid_SetPortValue(Port_A , 0b00001111);
							break;

						case 'b':

							DIO_Vid_SetPortValue(Port_A , 0b11111111);

							break;
						case 'c':

							DIO_Vid_SetPinValue(Port_B, pin6, PinHigh);

							break;
						case 'd':

							DIO_Vid_SetPortValue(Port_A , PinLow);
							DIO_Vid_SetPinValue(Port_B, pin6, PinLow);
							break;

						case 'e':
							flag = 1;//out of while loop ( operations )
							DIO_Vid_SetPortValue(Port_A, PinLow);
							DIO_Vid_SetPinValue(Port_B, pin6, PinLow);
							break;

					}//end of switch condition (operation)

				}//end of while loop ( operations )

			}//end of if condition ( correct pass )

		}//end of else if condition
		UART_VidSendData('\n');
	}//end of first while

}//end of main
