


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,	//8
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,	//16
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,	//24
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	LOW,
	HIGH
}DIO_PinVoltage_type;

//fun fact about the position of this extern:
//I tried to make it at the top of the code but I got multiple errors, why?
//because it was before declaring the enum (DIO_PinStatus_type) //done
extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];


//explanations for each fn is in the .c file for further info

void DIO_InitPin2(DIO_Pin_type pin_num,DIO_PinStatus_type status);
void DIO_Init(void);
void DIO_WritePin(DIO_Pin_type pin_num ,DIO_PinVoltage_type volt);
DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin_num);			//not checked yet
/* output only
*pin PINA0:PIND7  */

void DIO_TogglePin(DIO_Pin_type pin_num);
void DIO_WritePort(DIO_Port_type port,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);				//not checked yet





#endif /* DIO_INTERFACE_H_ */