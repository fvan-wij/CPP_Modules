#include <fstream>
#include <iostream>
#include <filesystem>
#include <climits>

#include "BitcoinExchange.hpp"

#define ARG_INPUT 1

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

bool	validDate(const std::string& date)
{
		std::stringstream ss(date);
		int year, month, day;
		char delimiter;
		ss >> year >> delimiter >> month >> delimiter >> day;

		if (std::to_string(year).length() != 4 || month > 12 || day > 31)
			return false;
		return true;
}

void	calcExchangeRatesFromFile(std::filesystem::path inputFile, BitcoinExchange& handler)
{
	std::string line;
	float		value = 0.0f;
	std::ifstream inFile(inputFile);
	while (std::getline(inFile, line))
	{
		if (line.empty())
		{
			continue;
		}

		size_t	divider = line.find("|");
		if (divider == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date 	= line.substr(0, line.find("|"));
		if (date.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (not validDate(date))
		{
			std::cerr << "Error: bad date => " << line << std::endl;
			continue;
		}

		try
		{
			value 	= std::stof(line.substr(line.find("|") + 1));
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			auto 		total 	= handler.getPriceAtDate(date).value_or(0) * value;
			std::cout << date << " => " << value << " = " << total << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Program requires valid input to run (e.g. ./btc input.txt)" << std::endl;
		return -1;
	}

	std::filesystem::path inputFile(argv[ARG_INPUT]);

	if (not validInput(inputFile))
	{
		return -2;
	}

	try
	{
		std::filesystem::path exchangePath("data.csv");
		BitcoinExchange handler(exchangePath);
		calcExchangeRatesFromFile(inputFile, handler);
	}
	catch (std::exception &e)
	{
		std::cout << "Error occurred: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
