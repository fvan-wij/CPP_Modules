#include <iostream>
#include <fstream>
#include <string>
#include "Replace.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

bool isInputValid(int argc, char *input[]){
    std::ifstream sourceFile;

    if (argc != 4)
    {
        std::cout << "Error: program must take <filename> followed by <string 1> and <string 2>" << std::endl;
        return false;
    }
    sourceFile.open(input[0]);
    if (!sourceFile.is_open())
    {
        std::cout << "Error: file cannot be opened" << std::endl;
        return false;
    }
    sourceFile.close();
    return true;
}

int main (int argc, char *argv[])
{
    if (!isInputValid(argc, &argv[1])){
		return EXIT_FAILURE;
	}
		
	Replace file(argv[1]);

	if (file.replacePattern(argv[2], argv[3]) == 0){
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}
