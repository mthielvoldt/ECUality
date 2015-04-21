#pragma once

#define SCALE_SIZE_MAX	20
#define SCALE_SIZE_MIN	2

class Scale
{
public:
	Scale(int x_lower_, int x_upper_, int y_lower_, int y_upper_, unsigned char n_p = 8);
	~Scale();

	static const char write(void * obj_ptr);
	static const char read(void * obj_ptr);
	static const char load(void * obj_ptr);
	static const char save(void * obj_ptr);

	int interpolate( int x_key);	

	int x[SCALE_SIZE_MAX], y[SCALE_SIZE_MAX];		// arrays that define a line for scaling inputs to outputs. 
	int x_upper, x_lower;						// upper/lower limits for elements of x
	int y_upper, y_lower;						// upper/lower limits for elements of y
	unsigned int n;								// the number elements in each array x, y
	unsigned int ee_address;

private:
	const bool verify(const int new_x[], const int new_y[], const int new_n);
	const unsigned int getEEAddy(unsigned int size);					// returns the last eeprom address 
};
