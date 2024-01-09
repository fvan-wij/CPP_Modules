#pragma once
# include <iostream>
# include <string>


class Contact
{
    private:
        std::string _name;
        std::string _last_name;
        std::string _nickname;
        std::string _phonenumber;
        std::string _secret;

    public:
    Contact();
    ~Contact();

    void setName(std::string name);
    std::string getName();

    void setLastName(std::string last_name);
    std::string getLastName();

    void setNickname(std::string nickname);
    std::string getNickname();

    void setPhonenumber(std::string phonenumber);
    std::string getPhonenumber();

    void setSecret(std::string secret);
    std::string getSecret();
};
