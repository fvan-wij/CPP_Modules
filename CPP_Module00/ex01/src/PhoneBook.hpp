#pragma once

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>
# include <sstream>

# define CONTACT_LIMIT 8

class PhoneBook {
    private:
        Contact contacts[CONTACT_LIMIT];
        int     _contactId;
        int     _nContacts;
        bool    _exit;
        void    truncateContact(std::string input);

    public:
        PhoneBook();
        ~PhoneBook();

        void add();
        void search();
        void exit();
        void getContact();
        bool terminate();

};