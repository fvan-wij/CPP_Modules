#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
    std::ifstream file("19920104_091532.log");
    std::string line;
    int i;

    i = 0;
    while (std::getline(file, line))
    {
        i = line.find("accounts:");
        if (i != -1)
        {
            std::string temp;
            while (line[i] != ';')
            {
                if (isdigit(line[i]))
                    temp.push_back(line[i]);
                i++;
            }
            // return (stoi(temp));
            std::cout << "Temp: " << stoi(temp) << std::endl;
        }
    }
}