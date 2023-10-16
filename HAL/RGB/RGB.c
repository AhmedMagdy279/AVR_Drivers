#include "../../LIB/StdTypes.h"
#include "../../LIB/MemMap.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timers/Timers_Interface.h"
#include "RGB_Interface.h"
#include "RGB_Private.h"

static volatile u8 TIMER2_INT_check=0;

void RGB_Init(void)
{
	//starting the code with a test
	//setting the color with black
	OCR1B=254;
	OCR1A=254;
	OCR0=254;
}

void RGB_SetColorCode(u8 c_Red, u8 c_green, u8 c_blue)
{
	//we are gonna use OC1B:R , OC1A:G , OC0:B 
	OCR1B	= (c_Red==255)? --c_Red: c_Red;	
	OCR1A	= (c_green==255)? --c_green: c_green;	
	OCR0	= (c_blue==255)? --c_blue: c_blue;	
}

static void RGB_delay()
{
	DIO_TogglePin(PINC0);
	TIMER2_INT_check=1;
}

void RGB_ChangeColor(u8 c1R,u8 c1G,u8 c1B, u8 c2R,u8 c2G,u8 c2B)
{
	///////////////////// ERROR WITH THIS TIMER PRESCALER //////////////////////////////
	//we will use timer 2 to change the color gradually
	//Worst Case Scenario: to change color from 0 to 255 and the max time this function will take 2 seconds max
	//and we got the tick = 128 usec (for 8 MHZ mcu and 1024 prescaler)
	//so we are gonna make the OC2 clear every 8 msec which every almost 63 ticks 
	//interrupt is gonna go every 8 msec (it's a lot but just to see the change in color gradually)
	OCR2=63;
	RGB_SetColorCode(c1R,c1G,c1B);
	TIMER2_OC_SetCallBack(RGB_delay);
	TIMER2_OC_InterruptEnable();
	while(c1R!=c2R || c1G!=c2G || c1B!=c2B)
	{	
		if(TIMER2_INT_check)
		{
			if (c1R!=c2R)
			RGB_SetColorCode(++c1R,c1G,c1B);
			
			if (c1G!=c2G)
			RGB_SetColorCode(c1R,++c1G,c1B);
			
			if (c1B!=c2B) 
			RGB_SetColorCode(c1R,c1G,++c1B);
			
			TIMER2_INT_check=0;
		}
	}
}

void RGB_SetColorName(RGB_COLORS c)
{
	RGB_SetColorCode(RGB_COLORS_CODE[c][0],RGB_COLORS_CODE[c][1],RGB_COLORS_CODE[c][2]);
}


