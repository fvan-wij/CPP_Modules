#include <iostream>

int main(void)
{
    std::string thought = "HI THIS IS BRAIN";

    std::string *strPtr = &thought;
    std::string &strRef = thought;

    std::cout   << "Memory address of the OG string: "
                << &thought << std::endl
                << "Memory address that the strPtr points to: "
                << &(*strPtr) << std::endl
                << "Memory address that the strRef points to: " 
                << &strRef << std::endl;
    return 0;
}