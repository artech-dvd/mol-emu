#include <iostream>

// C++ does not have 24-bit integers, so this thingy allows us to make our own
struct int24{
    unsigned int data : 24;
};

bool and_func(int24 x, int24 y) {
	// Returns both of the first bit of X and Y are both true
	// Sorry for the fancy unreadable math, it's the solution I found to this on StackOverflow
	return ( ( (x) & ( 1 << 1 )) >> 1) &&  ( ( (y) & ( 1 << 1 )) >> 1);
}
int main() {
	
	// Set both X and Y to true
	int24 x = 1;
	int24 y = 1;

	// Pass X and Y into our "AND" function and print it
	std::cout << and_func(x, y) << "/n";
	return 0;
}

