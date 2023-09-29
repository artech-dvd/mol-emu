#include <iostream>

// C++ does not have 24-bit integers, so this thingy allows us to make our own
struct uint24
{
     unsigned int  int24 : 24;
};


bool and_func(int x, int y) {
	// Returns both of the first bit of X and Y are both true
	// Sorry for the fancy unreadable math, it's the solution I found to this on StackOverflow
	return ( ( x & ( 1 << 0 )) >> 0) &&  ( ( y & ( 1 << 0 )) >> 0);
}
int main() {
	
	// Set both X and Y to 1
	uint24 x;
	x.int24 = 1;

	uint24 y;
	y.int24 = 1;

	// Pass X and Y into our "AND" function and print it
	std::cout << and_func(x.int24, y.int24) << "\n";
	return 0;
}

