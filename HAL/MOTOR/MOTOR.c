#include "../../LIB/StdTypes.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "MOTOR_Interface.h"
#include "../../CFG/MOTOR_CFG.h"

void MOTOR_Init()
{
	for(MOTOR_Type i=M1;i<TOTAL_MOTORS;i++)
		MOTOR_Stop(i);
}

void MOTOR_Stop(MOTOR_Type m)
{
	//DIO_WritePin(MotorPinsArr[m][IN1],LOW);
	//DIO_WritePin(MotorPinsArr[m][IN2],LOW);
	
	DIO_WritePin(MotorPinsArr2[m].in1,LOW);
	DIO_WritePin(MotorPinsArr2[m].in2,LOW);
	/*switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;
	}*/
}
void MOTOR_Stop_ALL()
{
	for(MOTOR_Type i=M1;i<TOTAL_MOTORS;i++)
	MOTOR_Stop(i);
}

void MOTOR_CW(MOTOR_Type m)
{
	DIO_WritePin(MotorPinsArr2[m].in1,HIGH);
	DIO_WritePin(MotorPinsArr2[m].in2,LOW);
}
void MOTOR_CW_ALL()
{
	for(MOTOR_Type i=M1;i<TOTAL_MOTORS;i++)
		MOTOR_CW(i);
}

void MOTOR_CCW(MOTOR_Type m)
{
	DIO_WritePin(MotorPinsArr2[m].in1,LOW);
	DIO_WritePin(MotorPinsArr2[m].in2,HIGH);
	/*switch(m)
	{
		case M1:
		DIO_WritePin(M1_IN1,HIGH);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;
	}*/
}
void MOTOR_CCW_ALL()
{
	for(MOTOR_Type i=M1;i<TOTAL_MOTORS;i++)
		MOTOR_CCW(i);
}

/* speed 0:100*/
/* speed 0:1400*/
void MOTOR_Speed(MOTOR_Type m,u8 speed)
{
	
}