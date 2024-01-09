#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void    printInstructions()
{
    std::cout
        << "Please enter one of the following commands:" << std::endl
        << std::endl
        << "ADD - Adds a new contact to the phonebook" << std::endl
        << "SEARCH - Searches and displays your contacts" << std::endl
        << "EXIT - exits the program." << std::endl
        << std::endl;
}

int main(void)
{
    std::string input;
    PhoneBook   phonebook;

    phonebook = PhoneBook();
    printInstructions();
    while (!phonebook.terminate())
    {
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            phonebook.add();
            std::cout << "--------------------------" << std::endl;
            std::cout << "Contact added succesfully!" << std::endl;
            std::cout << "--------------------------" << std::endl << std::endl;
        }
        else if (input == "SEARCH")
        {
            phonebook.search();
            phonebook.getContact();
        }
        else if (input == "EXIT")
        {
            phonebook.exit();
        }
    }
}