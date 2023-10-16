#ifndef RGB_PRIVATE_H_
#define RGB_PRIVATE_H_

//I know that it's preferable and more efficient to make this 2D array in CFG (and makes more sense as well)
//but for a practice of private file I decided to use it here
//**CONSIDER: we could have made this 2D array in the CFG and extern the array here and then include private file in the .c

u8 RGB_COLORS_CODE[20][3] = {
	{255, 0, 0},        // Red
	{0, 255, 0},        // Green
	{0, 0, 255},        // Blue
	{255, 255, 0},      // Yellow
	{0, 255, 255},      // Cyan
	{255, 0, 255},      // Magenta
	{0, 0, 0},          // Black
	{255, 255, 255},    // White
	{128, 128, 128},    // Gray
	{192, 192, 192},    // Silver
	{128, 0, 0},        // Maroon
	{128, 128, 0},      // Olive
	{0, 0, 128},        // Navy
	{128, 0, 128},      // Purple
	{0, 128, 128},      // Teal
	{255, 165, 0},      // Orange
	{0, 255, 0},        // Lime
	{255, 192, 203},    // Pink
	{165, 42, 42},      // Brown
	{255, 215, 0}       // Gold
};




#endif /* RGB_PRIVATE_H_ */

