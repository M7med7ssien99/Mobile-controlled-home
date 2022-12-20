#include "STD_Types.h"
#include "BIT_Math.h"
#include "UART_Int.h"
#include "LCD_int.h"
#include "IMT_PROJECT_int.h"
#include <util/delay.h>

//GLOBAL VARIABLES
const u8 *arr[] = { (u8*)"alaa", (u8*)"mohamed", (u8*)"mavi", (u8*)"ahmed", (u8*)"omar", (u8*)"yasmeen", (u8*)"asmaa", (u8*)"blabla", (u8*)"bbbb", (u8*)"aaaa"};
const u8 *arr_pass[] = {(u8*)"12345678", (u8*)"12345", (u8*)"2222", (u8*)"3333", (u8*)"1111", (u8*)"9999", (u8*)"5555", (u8*)"54678", (u8*)"54632", (u8*)"45673"};
u8 state, state_pass;

void UART_Vid_RecieveUserName(u8 *user)
{
	u8 local_var = 0;
	user[local_var] = UART_u8RecieveData(); //receive first character
	UART_VidSendData(user[local_var]);
	LCD_vid_GoToX(1,local_var);
	LCD_vid_SendData(user[local_var]);
	while(user[local_var] != '=')
	{
		local_var++; // increment the counter
		user[local_var] = UART_u8RecieveData();//receive second character
		UART_VidSendData(user[local_var]);
		LCD_vid_GoToX(1,local_var);
		LCD_vid_SendData(user[local_var]);
	}
	user[local_var] = '\0' ; //free the last index of the array from '=' sign
}


void UART_Vid_RecievePass(u8 *pass)
{
	u8 local_var = 0;
	pass[local_var] = UART_u8RecieveData();
	UART_VidSendData('*');
	LCD_vid_GoToX(1,local_var);
	LCD_vid_SendData('*');
	while(pass[local_var] != '=')
	{
		local_var++;
		pass[local_var] = UART_u8RecieveData();
		UART_VidSendData('*');
		LCD_vid_GoToX(1,local_var);
		LCD_vid_SendData('*');
	}
	pass[local_var] = '\0' ;
}





u8 Check_User(u8 *user)
{
	u8 counter1=0 ; //Refers to user names
	u8 counter2=0 ;//Refers to letters of users name
	state = 0;
	while(counter1 < 10)//loop on 10 user names
	{
		counter2=0;//first character
			while(user[counter2] == arr[counter1][counter2] && user[counter2] != '\0' && arr[counter1][counter2] != '\0')
			{
				counter2++; //next character
			}
			if(user[counter2] == '\0' && arr[counter1][counter2] == '\0')
			{
				state = counter1+1; //identifies user name
				break;//get out of first while loop (loop on names)
			}
			else if(user[counter2] != '\0' || arr[counter1][counter2] != '\0')
			{
				state = wrong_name ;
				counter1++; // next user name
			}
	}
	return state;
}




u8 Check_Pass(u8 *pass, u8 x)
{
	u8 counter2 = 0;
	state_pass = 0;
	switch(x)
	{

	case User1:
		while(pass[counter2] == arr_pass[0][counter2] && pass[counter2] != '\0' && arr_pass[0][counter2] != '\0')
		{
			counter2++;//next character
		}

		if(pass[counter2] == '\0' && arr_pass[0][counter2] == '\0')//pass is correct
		{
			state_pass = User1;
		}

		else if(pass[counter2] != '\0' || arr_pass[0][counter2] != '\0')//pass is wrong
		{
			state_pass = wrong_pass ;
		}
		break;

	case User2:

		while(pass[counter2] == arr_pass[1][counter2] && pass[counter2] != '\0' && arr_pass[1][counter2] != '\0'){

			counter2++;
		}

		if(pass[counter2] == '\0' && arr_pass[1][counter2] == '\0'){

			state_pass = User2;
		}

		else if(pass[counter2] != '\0' || arr_pass[1][counter2] != '\0'){

			state_pass = wrong_pass ;
		}
		break;

	case User3:

		while(pass[counter2] == arr_pass[2][counter2] && pass[counter2] != '\0' && arr_pass[2][counter2] != '\0'){

			counter2++;
		}

		if(pass[counter2] == '\0' && arr_pass[2][counter2] == '\0'){

			state_pass = User3;
		}

		else if(pass[counter2] != '\0' || arr_pass[2][counter2] != '\0'){

			state_pass = wrong_pass ;
		}
		break;

	case User4:

				while(pass[counter2] == arr_pass[3][counter2] && pass[counter2] != '\0' && arr_pass[3][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[3][counter2] == '\0'){

					state_pass = User4;
				}

				else if(pass[counter2] != '\0' || arr_pass[3][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User5:

				while(pass[counter2] == arr_pass[4][counter2] && pass[counter2] != '\0' && arr_pass[4][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[4][counter2] == '\0'){

					state_pass = User5;
				}

				else if(pass[counter2] != '\0' || arr_pass[4][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User6:

				while(pass[counter2] == arr_pass[5][counter2] && pass[counter2] != '\0' && arr_pass[5][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[5][counter2] == '\0'){

					state_pass = User6;
				}

				else if(pass[counter2] != '\0' || arr_pass[5][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User7:

				while(pass[counter2] == arr_pass[6][counter2] && pass[counter2] != '\0' && arr_pass[6][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[6][counter2] == '\0'){

					state_pass = User7;
				}

				else if(pass[counter2] != '\0' || arr_pass[6][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User8:

				while(pass[counter2] == arr_pass[7][counter2] && pass[counter2] != '\0' && arr_pass[7][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[7][counter2] == '\0'){

					state_pass = User8;
				}

				else if(pass[counter2] != '\0' || arr_pass[7][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User9:

				while(pass[counter2] == arr_pass[8][counter2] && pass[counter2] != '\0' && arr_pass[8][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[8][counter2] == '\0'){

					state_pass = User9;
				}

				else if(pass[counter2] != '\0' || arr_pass[8][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	case User10:

				while(pass[counter2] == arr_pass[9][counter2] && pass[counter2] != '\0' && arr_pass[9][counter2] != '\0'){

					counter2++;
				}

				if(pass[counter2] == '\0' && arr_pass[9][counter2] == '\0'){

					state_pass = User10;
				}

				else if(pass[counter2] != '\0' || arr_pass[9][counter2] != '\0'){

					state_pass = wrong_pass ;
				}
		break;

	}//end of switch condition
	return state_pass;
}










