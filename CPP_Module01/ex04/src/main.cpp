#include <iostream>
#include <fstream>
#include <string>
#include "Replace.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[])
{
    //Open file or create file
    if (!isInputValid(argc, &argv[1]))
        return EXIT_FAILURE;

    //Read each line
    std::fstream   sourceFile;
    std::string     line;
    std::string     s1 = argv[2];
    std::string     s2 = argv[3];
    sourceFile.open(argv[1]);
    if (sourceFile.is_open())
    {
        while (std::getline(sourceFile, line))
        {
            if (line.find(s1))
            {
                
            }
        }
    }

    //Starting from line[i], look if match with S2
        //While no match i++ and write to file.replace;
        //Else, copy line to buffer, replace occurrence with S2, write buffer to file.replace;
}
