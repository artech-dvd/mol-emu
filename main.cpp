#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

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

int main(int argc, char *argv[]) {
	
	// Get user file name
	std::string file_name; 
	if (argc<2 || argc>3) {
		throw std::invalid_argument("Invalid number of arguments. Please specify a file name.");
	} else {
		file_name = argv[1];
	}

	// Import input code from the specified file and convert to string
	std::fstream file_input;
	file_input.open (file_name, std::ios::in | std::ios::app | std::ios::binary);

	std::string input((std::istreambuf_iterator<char>(file_input)),
                 std::istreambuf_iterator<char>());

	// Index of which character we're currently at in the code (THIS IS VERY IMPORTANT)
	long int read_index = 0;
	bool declare_command_end = true;



	// Vector containg all the variable names (of exp type) that we have declared (these will be used when we wanna access variables)
	std::vector<std::string> exp_variable_names;

	// Vector containg all the variable values(of exp type) that we have declared 
	std::vector<uint24> exp_variable_values;

	// std::cout << "Code input length: "<< input.size() << "\n"; // i assume temporary

	while (read_index < input.size()) {

		// TODO: Use the input string to recognize stuff as "commands"
		// When no known commands match the statement in the input code, throw an error and crash\


		// Declare code
		bool declare_command_end = true;
			if (input.substr(read_index, 8) == "declare ") {
				// Increase the read index by 8
				read_index += 8;
					while (declare_command_end) {

					int var_name_len;
					int var_value_len;
					bool declare_no_define = false;

					// Use a for loop to determine the length of the name
					for (int i = 0; input[read_index + i] != '=' && input[read_index + i] != ';' && input[read_index + i] != ','; i++) {
						var_name_len = i;
					}

					if (input[read_index + var_name_len + 1] == ';' || input[read_index + var_name_len + 1] == ',') {
						declare_no_define = true;
					}

					// Need to do this. Don't know why, it just fixed a problem.
					var_name_len++; // According to github copilot chat, 
					/*
					The selected code var_name_len++ increments the length of the variable name by 1. 
					This is needed because the program is parsing a variable declaration statement in 
					the input code, and it needs to keep track of the length of the variable name in 
					order to extract the name from the input code. By incrementing var_name_len,
					 the program ensures that it is reading the entire variable name from the input code.
					*/

					// Insert the variable name into the names table
					exp_variable_names.insert(exp_variable_names.begin(),input.substr(read_index, var_name_len));
					std::cout << "Variable added: "<< exp_variable_names[0] << "\n";

					// Increment the read index (plus 1, the equals sign isn't a number)
					read_index += var_name_len + 1;
					if (!declare_no_define) {
						for (int i = 0; input[read_index + i] != ';' && input[read_index + i] != ','; i++) {
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
						
						std::cout << "Variable value: "<< yes.int24 << "\n";
						// Insert the int24 into the values table
						exp_variable_values.insert(exp_variable_values.begin(), yes);
						read_index += var_value_len;
					} else {
						uint24 null_uint24;
						null_uint24.int24 = 0;
						exp_variable_values.insert(exp_variable_values.begin(), null_uint24);

					}
					std::cout << "\n";
					if (input[read_index] == ',') {
						// Increment the read index so it's not stuck on the comma
						read_index++;
						// Increment the read index until it's not pointing to a space
						while (input[read_index] == ' ') {
							read_index++;
						}
					} else if (input[read_index - 1] == ',') {
						// Increment the read index so it's not stuck on the comma
						read_index++;
						// Increment the read index until it's not pointing to a space
						while (input[read_index] == ' ') {
							read_index++;
						}
					} else {
						break;		
					}
			}
		}

		// Increase the read index
		read_index++;
	}
	std::cout << "Finished execution." << "\n";

	return 0;
}