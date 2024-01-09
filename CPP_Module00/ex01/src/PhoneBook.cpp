#include "PhoneBook.hpp"
#include <string>

bool    isStringNumber(std::string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return (false);
    }
    return (true);
}

PhoneBook::PhoneBook()
{
    _contactId = 0;
    _nContacts = 0;
    _exit = false;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add()
{
    std::string temp;
    contacts[_contactId] = Contact();

    std::cout << "Name: ";
    while (temp.length() == 0)
    {
        std::getline(std::cin, temp);
        if (temp.length() == 0)
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            std::cout << "Name: ";
        }
    }
    contacts[_contactId].setName(temp);
    temp.clear();

    std::cout << "Surname: ";
    while (temp.length() == 0)
    {
        std::getline(std::cin, temp);
        if (temp.length() == 0)
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            std::cout << "Surname: ";
        }
    }
    contacts[_contactId].setLastName(temp);
    temp.clear();

    std::cout << "Nickname: ";
    while (temp.length() == 0)
    {
        std::getline(std::cin, temp);
        if (temp.length() == 0)
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            std::cout << "Nickname: ";
        }
    }
    contacts[_contactId].setNickname(temp);
    temp.clear();

    std::cout << "Phonenumber: ";
    while (temp.length() == 0)
    {
        std::getline(std::cin, temp);
        if (temp.length() == 0)
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            std::cout << "Phonenumber: ";
        }
        else if (!isStringNumber(temp))
        {
            temp.clear();
            std::cout << "Error: field should contain numbers only" << std::endl;
            std::cout << "Phonenumber: ";
        }
    }
    contacts[_contactId].setPhonenumber(temp);
    temp.clear();

    std::cout << "Darkest secret: ";
    while (temp.length() == 0)
    {
        std::getline(std::cin, temp);
        if (temp.length() == 0)
        {
            std::cout << "Error: field cannot be empty" << std::endl;
            std::cout << "Darkest secret: ";
        }
    }
    contacts[_contactId].setSecret(temp);

    _contactId++;
    _nContacts++;
    if (_nContacts >= CONTACT_LIMIT)
        _nContacts = CONTACT_LIMIT;
    if (_contactId >= CONTACT_LIMIT)
        _contactId = 0;
    std::cout << std::endl;
}

void PhoneBook::search()
{
    std::string const sep = "|";

    std::cout << 
    std::setw(11) << "Index|" << 
    std::setw(11) << "Name|" << 
    std::setw(11) << "Surname|" << 
    std::setw(11) << "Nickname|" << std::endl;

    for (size_t i = 0; i < (size_t)_nContacts; i++)
    {
        std::cout << std::setw(10) << i + 1 << sep;
        if (contacts[i].getName().length() > 10)
            truncateContact(contacts[i].getName());
        else
            std::cout << std::setw(10) << contacts[i].getName() << sep;
        if (contacts[i].getLastName().length() > 10)
            truncateContact(contacts[i].getLastName());
        else
            std::cout << std::setw(10) << contacts[i].getLastName() << sep;
        if (contacts[i].getNickname().length() > 10)
            truncateContact(contacts[i].getNickname());
        else
            std::cout << std::setw(10) << contacts[i].getNickname() << sep;
        std::cout << std::endl;
    }
}

void    PhoneBook::truncateContact(std::string input)
{
    std::string const sep = "|";
    for (size_t i = 0; i < 9; i++)
    {
        std::cout << input[i];
    }
    std::cout << "." << sep;
}

void PhoneBook::exit()
{
    _exit = true;
}

void    PhoneBook::getContact()
{
    int index;
    bool succeeded;

    succeeded = false;
    std::string temp;
    std::cout << std::endl << "Insert index of contact to display: ";
    std::getline(std::cin, temp);
    index = (temp[0] - '0');
    while (!succeeded)
    {
        if (temp.length() > 1 || !isdigit(temp[0]) || temp[0] >= '9' || temp[0] == '0')
        {
            std::cout << "Error: index should be an integer between 1 - 8" << std::endl;
            std::cout << std::endl << "Insert index of contact to display: ";
            std::getline(std::cin, temp);
            index = (temp[0] - '0');
        }
        else if (contacts[index - 1].getName().length() == 0)
        {
            std::cout << std::endl << "--------------------------" << std::endl;
            std::cout << "Error: contact doesn't exist" << std::endl;
            std::cout << "--------------------------" << std::endl << std::endl;
            succeeded = true;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "--------------------------" << std::endl;
            std::cout << "Name: " << contacts[index - 1].getName() << std::endl;
            std::cout << "Surname: " << contacts[index - 1].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index - 1].getNickname() << std::endl;
            std::cout << "Number: " << contacts[index - 1].getPhonenumber() << std::endl;
            std::cout << "Secret: " << contacts[index - 1].getSecret() << std::endl;
            std::cout << "--------------------------" << std::endl << std::endl;
            succeeded = true;
        }
    }
}

bool PhoneBook::terminate()
{
    return (_exit);
}