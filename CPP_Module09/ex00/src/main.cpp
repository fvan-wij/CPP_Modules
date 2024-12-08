#include <fstream>
#include <iostream>
#include <filesystem>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Program requires input to run (e.g. ./btc input.txt)" << std::endl;
		return -1;
	}
	std::filesystem::path input_path(argv[1]);
	std::ifstream file(input_path);
	if (not file.good())
	{
		std::cerr << "Error opening input file" << std::endl;
		return -1;
	}

	try
	{
		std::filesystem::path exchange_path("data.csv");
		BitcoinExchange handler(exchange_path);
		std::string date = "2022-02-17";
		std:: cout << "Price at " << date << ": " << handler.getPriceAtDate(date);
	}
	catch (std::exception &e)
	{
		std::cout << "Error occurred: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
