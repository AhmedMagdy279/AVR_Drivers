#include "../../LIB/StdTypes.h"
#include "../../LIB/UTILS.h"
#include "UltraSonic_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../CFG/UltraSonic_CFG.h"
#include "../../MCAL/Timers/Timers_Interface.h"
#define  F_CPU   8000000
#include <util/delay.h>

//ultrasonic stuff
static volatile u8 flag=0;
static volatile u16 t1,t2;
u32 UltraSonic_Distance;
void UltraSonic_INT();

//we are gonna use ICP1 pin (PD6) as input capture mode
//to set it to rising edge trigger we need to set ICES1 bit to 1 otherwise clear it
//When a capture is triggered according to the ICES1 setting, the counter value is copied
//into the Input Capture Register (ICR1). The event will also set the Input Capture Flag
//(ICF1), and this can be used to cause an Input Capture Interrupt, if this interrupt is
//enabled.
//When the ICR1 is used as TOP value, the ICP1 is disconnected and consequently
//the input capture function is disabled.

//to trigger the ultrasonic device there shall be high pulse for 10us
static void UltraSonic_trigger()
{
	DIO_WritePin(TriggerPin,HIGH);
	_delay_us(10);
	DIO_WritePin(TriggerPin,LOW);
}

void UltraSonic_init()
{
	//nothing to initiate
}

void UltraSonic_runnable()
{
	if (!flag)
	{
		UltraSonic_trigger();
		flag++;
	}
	
	if(flag==1)
	{
		Timer1_ICU_SetCallBack(UltraSonic_INT);
		Timer1_ICU_InterruptEnable();
		Timer1_InputCaptureEdge(RISING);
	}
	else if(flag==3)
	{
		//the eqn to calculate the distance(m/s)= ( 340 * T ) / 2
		//where speed of sound = 340 m/s , T: time the echo traveled , and divided by 2 for one way not both ways
		//to make the distance (cm/us) = ( 340*100 * T)/2*10^6 = ((((((((((((((((((			T/58          )))))))))))))
		UltraSonic_Distance= (t2-t1)/58;
		flag=0;
	}
	
}

u32 UltraSonic_GetDistance()
{
	return UltraSonic_Distance;
}

void UltraSonic_INT()
{
	if (flag==1)
	{
		t1=TIMER1_GetICUValue();
		Timer1_InputCaptureEdge(FALLING);
		flag=2;
	}
	else if(flag==2)
	{
		t2=TIMER1_GetICUValue();
		Timer1_ICU_InterruptDisable();
		flag=3;
	}
}