// Drops the first word in each line, preseving whitespace.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        bool inFirstWord = false;
	bool afterFirstWord = false; 
        std::string restOfLine;

        // Manually process each character
        for (char ch : line) {
	    if (afterFirstWord) {
		restOfLine += ch;
		continue;
	    } 
	    
            if (inFirstWord) {
                if (ch == ' ' || ch == '\t') {
		    inFirstWord = false;
		    afterFirstWord = true;
                } else {
		    continue;
		}
            } else {
                if (ch == ' ' || ch == '\t') {
		    restOfLine += ch;
                } else {
		    inFirstWord = true;
		}
            }
        }

        std::cout << restOfLine << std::endl;
    }

    file.close();
    return 0;
}
