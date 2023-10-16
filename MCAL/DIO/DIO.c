#include "../../LIB/StdTypes.h"
#include "../../LIB/MemMap.h"
#include "../../LIB/UTILS.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "../../CFG/DIO_CFG.h"



//alternatively we can use this function and it's easier to use as we only give the port and pin combined in one variable
//then decompose this variable in only 2 lines saving one attribute as input
void DIO_InitPin2(DIO_Pin_type pin_num ,DIO_PinStatus_type status)
{
	u8 pinNUM = pin_num % 8;
	DIO_Port_type portNUM = pin_num / 8;
	
	switch(status)
	{
		case OUTPUT:
		switch(portNUM)
		{
			case PA:
			SET_BIT(DDRA,pinNUM);
			CLR_BIT(PORTA,pinNUM);
			break;
			case PB:
			SET_BIT(DDRB,pinNUM);
			CLR_BIT(PORTB,pinNUM);
			break;
			case PC:
			SET_BIT(DDRC,pinNUM);
			CLR_BIT(PORTC,pinNUM);
			break;
			case PD:
			SET_BIT(DDRD,pinNUM);
			CLR_BIT(PORTD,pinNUM);
			break;
		}
		break;
		case INFREE:
		switch(portNUM)
		{
			case PA:
			CLR_BIT(DDRA,pinNUM);
			CLR_BIT(PORTA,pinNUM);
			break;
			case PB:
			CLR_BIT(DDRB,pinNUM);
			CLR_BIT(PORTB,pinNUM);
			break;
			case PC:
			CLR_BIT(DDRC,pinNUM);
			CLR_BIT(PORTC,pinNUM);
			break;
			case PD:
			CLR_BIT(DDRD,pinNUM);
			CLR_BIT(PORTD,pinNUM);
			break;
		}
		break;
		case INPULL:
		switch(portNUM)
		{
			case PA:
			CLR_BIT(DDRA,pinNUM);
			SET_BIT(PORTA,pinNUM);
			break;
			case PB:
			CLR_BIT(DDRB,pinNUM);
			SET_BIT(PORTB,pinNUM);
			break;
			case PC:
			CLR_BIT(DDRC,pinNUM);
			SET_BIT(PORTC,pinNUM);
			break;
			case PD:
			CLR_BIT(DDRD,pinNUM);
			SET_BIT(PORTD,pinNUM);
			break;
		}
		break;
	}
}

//we can use the following function at the beginning of the code to configure
//all the pins once using the CFG array for the 32 pins we have
void DIO_Init(void)
{
	for (DIO_Pin_type i=0;i<TOTAL_PINS;i++)
	DIO_InitPin2(i,DIO_PinsStatusArr[i]);
}

//we use this function to change the voltage on the O/P pins
//for a future VIP features::: we can make this function return enum msgs like ERROR! or DONE, why?
//because the user might wanna write on an Input pin so we shall give a feedback. But rest assured if he tried we will not allow it tho in the code
void DIO_WritePin(DIO_Pin_type pin_num ,DIO_PinVoltage_type volt)
{
	u8 pinNUM = pin_num % 8;
	DIO_Port_type portNUM = pin_num / 8;

	switch(portNUM)
	{
		case PA:
		if(READ_BIT(DDRA,pinNUM))
		{
			switch(volt)
			{
				case LOW:
				CLR_BIT(PORTA,pinNUM);
				break;
				case HIGH:
				SET_BIT(PORTA,pinNUM);
				break;
			}
		}
		break;
		case PB:
		if(READ_BIT(DDRB,pinNUM))
		{
			switch(volt)
			{
				case LOW:
				CLR_BIT(PORTB,pinNUM);
				break;
				case HIGH:
				SET_BIT(PORTB,pinNUM);
				break;
			}
		}
		break;
		case PC:
		if(READ_BIT(DDRC,pinNUM))
		{
			switch(volt)
			{
				case LOW:
				CLR_BIT(PORTC,pinNUM);
				break;
				case HIGH:
				SET_BIT(PORTC,pinNUM);
				break;
			}
		}
		break;
		case PD:
		if(READ_BIT(DDRD,pinNUM))
		{
			switch(volt)
			{
				case LOW:
				CLR_BIT(PORTD,pinNUM);
				break;
				case HIGH:
				SET_BIT(PORTD,pinNUM);
				break;
			}
		}
		break;
	}
}

DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin_num)
{
	u8 pinNUM = pin_num % 8;
	DIO_Port_type portNUM = pin_num / 8;
	
	//DIO_PinVoltage_type tmpVAR=LOW;
	
	switch(portNUM)
	{
		case PA:
		if (READ_BIT(PINA,pinNUM))
		return HIGH;
		else
		return LOW;
		break;
		
		case PB:
		if (READ_BIT(PINB,pinNUM))
		return HIGH;
		else
		return LOW;
		break;
		
		case PC:
		if (READ_BIT(PINC,pinNUM))
		return HIGH;
		else
		return LOW;
		break;
		
		case PD:
		if (READ_BIT(PIND,pinNUM))
		return HIGH;
		else
		return LOW;
		break;
		
		default:
		return LOW;
	}
}

void DIO_TogglePin(DIO_Pin_type pin_num)
{
	u8 pinNUM = pin_num % 8;
	DIO_Port_type portNUM = pin_num / 8;

	switch(portNUM)
	{
		case PA:
		if(READ_BIT(PORTA,pinNUM))
		DIO_WritePin(pin_num,LOW);
		else
		DIO_WritePin(pin_num,HIGH);
		break;
		case PB:
		if(READ_BIT(PORTB,pinNUM))
		DIO_WritePin(pin_num,LOW);
		else
		DIO_WritePin(pin_num,HIGH);
		break;
		case PC:
		if(READ_BIT(PORTC,pinNUM))
		DIO_WritePin(pin_num,LOW);
		else
		DIO_WritePin(pin_num,HIGH);
		break;
		case PD:
		if(READ_BIT(PORTD,pinNUM))
		DIO_WritePin(pin_num,LOW);
		else
		DIO_WritePin(pin_num,HIGH);
		break;
	}
}

void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA = data;
		break;
		case PB:
		PORTB = data;
		break;
		case PC:
		PORTC = data;
		break;
		case PD:
		PORTD = data;
		break;
	}
}
u8 DIO_ReadPort(DIO_Port_type port)
{
	switch(port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
		
		default:
		return 0;
	}
}
