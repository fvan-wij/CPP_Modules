#pragma once
#include <iostream>
#include <fstream>


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