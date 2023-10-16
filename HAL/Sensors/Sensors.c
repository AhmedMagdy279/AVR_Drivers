#include "../../LIB/StdTypes.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../CFG/Sensors_Cfg.h"
#include "Sensors_Interface.h"
#define  ADC_X  0
#define POINTS  10
#define  TEMP_Y 1

static u16 TEMP=300;
static u16 Smoke=0;

// u16 arr[POINTS][2]={    {0,10}
// 				,	{100,20}
// 					{200,33}
// 					{300,60}
// 					{400,100}
// 					{0,10}
// 					{0,10}};

// u16 temp(u16 adc)//370
// {
// 	u8 i;
// 	for (i=0;i<POINTS;i++)
// 	{
// 		if (adc<arr[i][ADC_X])
// 		{
// 			temp=inter(adc,arr[i-1][ADC_X],arr[i][ADC_X],arr[i][TEMP_Y-1],arr[i][TEMP_Y-1]);
// 		}
// 	}
// }

void SENSORS_TEMP_Read(void)
{
	u16 volt=ADC_VoltRead(LM35_CH);
	SENSORS_SetTEMP(volt);
}
void SENSORS_SetTEMP(u16 temp)
{
	TEMP=temp;
}
u16 SENSORS_GetTEMP(void)
{
	return TEMP;
}
void SENSORS_Smoke_Read(void)
{
	u16 adc=ADC_VoltRead(POT_1k);
	SENSORS_SetSmoke((adc*(u32)100)/5000);
}
void SENSORS_SetSmoke(u16 smk)
{
	Smoke=smk;
}
u16 SENSORS_GetSmoke(void)
{
	return Smoke;
}

u16 PRESS_Read(void)
{
	u16 adc=ADC_Read(MPX4115_CH);
	
	u16 press= ((((u32)1000*(adc-55))+460)/921)+150;
	
	return press;
	
}

u8 POT_Read(void)
{
	
}