
#ifndef SENSORS_INTERFACE_H_
#define SENSORS_INTERFACE_H_


/* return temp c*10*/
void SENSORS_TEMP_Read(void);
void SENSORS_SetTEMP(u16 temp);
u16 SENSORS_GetTEMP(void);

void SENSORS_Smoke_Read(void);
void SENSORS_SetSmoke(u16 smk);
u16 SENSORS_GetSmoke(void);





#endif /* SENSORS_INTERFACE_H_ */