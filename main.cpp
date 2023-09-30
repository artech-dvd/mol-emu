#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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



	// Vector containg all the variable names (of exp type) that we have declared (these will be used when we wanna access variables)
	std::vector<std::string> exp_variable_names;

	// Vector containg all the variable values(of exp type) that we have declared 
	std::vector<uint24> exp_variable_values;

	std::cout << "Input length: "<< input.size() << "\n";

	while (read_index < input.size()) {

		// Declare code
		if (input.substr(read_index, 7) == "declare") {
			// Increase the read index by 8
			read_index += 8;

			int var_name_len;
			int var_value_len;

			// Use a for loop to determine the length of the name
			for (int i = 0; input[read_index + i] != '='; i++) {
				var_name_len = i;
			}

			// Need to do this. Don't know why, it just fixed a problem.
			var_name_len++;

			// Insert the variable name into the names table
			exp_variable_names.insert(exp_variable_names.begin(),input.substr(read_index, var_name_len));
			std::cout << exp_variable_names[0] << "\n";

			// Increment the read index (plus 1, the equals sign isn't a number)
			read_index += var_name_len + 1;

			for (int i = 0; input[read_index + i] != ';'; i++) {
				var_value_len = i;
			}


			var_value_len++;
			/// CONVERTING STRING TO INT24

			// Convert from string to int
			unsigned int var_value; 
			std::stringstream conv; 
			conv << (input.substr(read_index, var_value_len) );
			conv >> var_value;

			// Convert from int to int24 
			uint24 yes;
			yes.int24 = var_value;

			/// END
			
			std::cout << yes.int24 << "\n";
			// Insert the int24 into the values table
			exp_variable_values.insert(exp_variable_values.begin(), yes);

		}

		// Increase the read index
		read_index++;
	}
	std::cout << "done lol" << "\n";

	return 0;
}

