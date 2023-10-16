#include "../../LIB/StdTypes.h"
#include "../../LIB/MemMap.h"
#include "../../LIB/UTILS.h"
#include "ADC_Interface.h"
#include "../../CFG/ADC_CFG.h"
#define  F_CPU   8000000
#include <util/delay.h>

static u8 ADC_BusyFlag;

static void (*ADC_Fptr) (void)= NULLPTR;

void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	//setting the Vref
	switch (vref)
	{
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
		default:
		ADMUX &= 0x3F;			//clearing REFS0 and REFS 1
		ADMUX |= (scaler<< REFS0);	//setting the new values we got
		break;
	}
	
	//setting the prescaler
	ADCSRA &= 0xF8;			//clearing the prescaler pins in the ADCSRA register to wait for the adding process
	scaler |= 0x07;			//clearing every other pin for the scaler except those that are gonna be added on the ADCSRA
	ADCSRA |= scaler;		//adding the scaler values to the ADCSRA register
	
	//we shall consider this line for power consumption or usage in the upcoming apps/projects
	//if we want to save power we can make the enable only when we need in an indepndant function
	//also if we want to change Vref mid project we need to disable and enable the MC 
	ADCSRA |= (1<<ADEN);
}

void ADC_StartConversion(ADC_Channel_type CH)
{
	if (ADC_BusyFlag==0)
	{
		//first we need to clear the channel bits that we are gonna get the data on
		ADMUX&=0XE0;//11100000
		ADMUX|=(CH & 0x07);
		
		//then we start conversion
		//ADCSRA |= (1<<ADSC);
		SET_BIT(ADCSRA,ADSC);
		
		//we are gonna use polling instead of blocking
		//ADC_BusyFlag=1;

	}
	
	
	//busy wait until conversion ends
	while(READ_BIT(ADCSRA,ADSC));		//this line shall be in the ADC_READ and busy flag replacing it
}

u16 ADC_Read(ADC_Channel_type CH)
{
	u16 ADC_value=0;
	//conversion is in the main function and we should add busy flag 
	ADC_StartConversion(CH);
	
	//add the data after conversion ends
	/* IF adle==0*/
	ADC_value  = ADCL;
	ADC_value |= (ADCH << 8);
	/* IF adle==1*/
	//u16 adc=ADCL>>6;
	//adc=adc|ADCH<<2;
	
   
	return ADC_value;
}

/* return mv*/
u16 ADC_VoltRead(ADC_Channel_type CH)
{
	u16 adc=ADC_Read(CH);
	u16 Vout_mV = (adc *(u32) 5000) / 1024;
	return Vout_mV;
 }

u8 ADC_GetReadPerodic(u16*pdata)
{
	return;
}
u16 ADC_GetRead(void)
{
	return;
}
u16 ADC_GetReadNoblock(void)
{
	return;
}
