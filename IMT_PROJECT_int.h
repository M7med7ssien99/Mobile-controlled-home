#ifndef IMT_PROJECT_INT_H
#define IMT_PROJECT_INT_H


#define User1       1
#define User2       2
#define User3       3
#define User4		4
#define User5		5
#define User6		6
#define User7		7
#define User8		8
#define User9		9
#define User10		10

#define wrong_pass		 0

#define wrong_name		20


//funcs prototyps
void UART_Vid_RecieveUserName(u8 *user);
void UART_Vid_RecievePass(u8 *pass);
u8 Check_User(u8 *user);
u8 Check_Pass(u8 *pass, u8 x);


#endif
