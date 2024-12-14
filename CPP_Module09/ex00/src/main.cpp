#include <fstream>
#include <iostream>
#include <filesystem>

#include "BitcoinExchange.hpp"

bool	validInput(std::filesystem::path inputPath)
{
	std::ifstream file(inputPath);

	if (not file.good())
	{
		std::cerr << "Error opening input file" << std::endl;
		return false;
	}

	if (inputPath.extension() != ".txt")
	{
		std::cerr << "Incorrect extension: " + inputPath.extension().string() << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Program requires input to run (e.g. ./btc input.txt)" << std::endl;
		return -1;
	}

	std::filesystem::path inputPath(argv[1]);

	if (not validInput(inputPath))
	{
		return -2;
	}

	try
	{
		std::filesystem::path exchange_path("data.csv");

		BitcoinExchange handler(exchange_path);


		std::string line;
		std::ifstream inFile(inputPath);
		while (std::getline(inFile, line))
		{
			std::string date 	= line.substr(0, line.find("|"));
			float		value 	= std::stof(line.substr(line.find("|") + 1));
			auto 		total 	= handler.getPriceAtDate(date).value_or(0) * value;
			std:: cout << date << " => " << value << " = " << total << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error occurred: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
