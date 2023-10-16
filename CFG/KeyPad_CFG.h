#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
#include "../LIB/StdTypes.h"
#include "../HAL/KeyPad/KeyPad_Interface.h"

#define ROWS 4
#define COLS 4

#define FirstTrigger  PINB4		//since the keypad is 4x4 so we have 4 triggers starting from this one (PB4-->PB7)
#define FirstReceiver PIND2		//and as well 4 input receivers (PD2-->PD5)
 
#define NO_KEY 'T'

u8 Keys_ARR [ROWS][COLS]= {
	{'7' ,'8' ,'9' ,'/'},
	{'4' ,'5' ,'6' ,'*'},
	{'1' ,'2' ,'3' ,'-'},
	{'C' ,'0' ,'=' ,'+'},
};


#endif /* KEYPAD_CFG_H_ */