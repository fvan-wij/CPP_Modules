#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void Contact::setName(std::string name)
{
    _name = name;
}

std::string Contact::getName()
{
    return (_name);
}

void Contact::setLastName(std::string last_name)
{
    _last_name = last_name;
}

std::string Contact::getLastName()
{
    return (_last_name);
}

void Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}

std::string Contact::getNickname()
{
    return (_nickname);
}

void Contact::setPhonenumber(std::string phonenumber)
{
    _phonenumber = phonenumber;
}

std::string Contact::getPhonenumber()
{
    return (_phonenumber);
}

void Contact::setSecret(std::string secret)
{
    _secret = secret;
}

std::string Contact::getSecret()
{
    return (_secret);
}