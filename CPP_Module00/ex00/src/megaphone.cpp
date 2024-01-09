#include <iostream>

void    trim_start(std::string & str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
        else
            return ;
    }
}

void    trim_end(std::string & str)
{
    for (size_t i = str.size() - 1; i > 0; i--)
    {
        if (str[i] == ' ')
            str.erase(str.begin() + i);
        else
            return ;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (size_t i = 1; argv[i]; i++)
        {
            std::string megaphone_str = argv[i];
            trim_start(megaphone_str);
            trim_end(megaphone_str);
            for (size_t i = 0; i < megaphone_str.size(); i++)
            {
                char c = toupper(megaphone_str[i]);
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}