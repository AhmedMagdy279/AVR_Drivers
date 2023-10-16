
#ifndef RGB_INTERFACE_H_
#define RGB_INTERFACE_H_

typedef enum{
	Red=0,
	Green,
	Blue,
	Yellow,
	Cyan,
	Magenta,
	Black,
	White,
	Gray,
	Silver,
	Maroon,
	Olive,
	Navy,
	Purple,
	Teal,
	Orange,
	Lime,
	Pink,
	Brown,
	Gold
	}RGB_COLORS;

void RGB_Init(void);

void RGB_SetColorCode(u8 c_Red, u8 c_green, u8 c_blue);

void RGB_ChangeColor(u8 c1R,u8 c1G,u8 c1B, u8 c2R,u8 c2G,u8 c2B);

void RGB_SetColorName(RGB_COLORS c);

#endif /* RGB_INTERFACE_H_ */