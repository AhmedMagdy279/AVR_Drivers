#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "../LIB/StdTypes.h"
#include "../HAL/LCD/LCD_Interface.h"



//4 bit cofiguration

//defining the pins that we are gonna work on:
#define LCD_RS		PINB0		//Regiseter select: 0--> command, 1-->data transfer
#define LCD_EN		PINB1		//enabling pulses
#define LCD_D4		PINA3		//from D4 to D7 are the data transfer pins
#define LCD_D5		PINA4
#define LCD_D6		PINA5
#define LCD_D7		PINA6
#define LCD_PORT	PA



/*
//8-bit configuration
//defining the pins that we are gonna work on:
#define LCD_RS		PINB0		//Regiseter select: 0--> command, 1-->data transfer
#define LCD_EN		PINB1		//enabling pulses
#define LCD_D0		PINA0		//from D0 to D7 are the data transfer pins
#define LCD_D1		PINA1
#define LCD_D2		PINA2
#define LCD_D3		PINA3
#define LCD_D4		PINA4
#define LCD_D5		PINA5
#define LCD_D6		PINA6
#define LCD_D7		PINA7
#define LCD_PORT	PA
*/


#endif /* LCD_CFG_H_ */