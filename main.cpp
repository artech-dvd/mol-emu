#include <iostream>
#include <vector>

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
	
	// Input code (hard coded at the moment)
	std::string input = "declare nchar=80;";

	// Index of which character we're currently at in the code (THIS IS VERY IMPORTANT)
	long int read_index = 0;
	std::string current_command;

	// Vector containg all the variable names (of exp type) that we have declared (these will be used when we wanna access variables)
	std::vector<std::string> exp_variable_names;

	// Vector containg all the variable values(of exp type) that we have declared 
	std::vector<uint24> exp_variable_values;

	exp_variable_names.insert(exp_variable_names.begin(),"test");

	std::cout << input.size() << "\n";

	while (read_index < input.size()) {
		if (input[read_index] == 'd') {
			std::cout << "d" << "\n";
		}
		read_index++;
	}
	std::cout << "done lol" << "\n";

	return 0;
}

