#include "BitcoinExchange.hpp"

#include <fstream>
#include <filesystem>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::filesystem::path& exchangeDataPath)
{
	if (exchangeDataPath.extension() != ".csv")
	{
		throw std::invalid_argument("Incorrect extension: " + exchangeDataPath.extension().string());
	}

	std::ifstream file(exchangeDataPath);

	if (not file.good())
	{
		throw std::runtime_error("Error opening file: " + exchangeDataPath.filename().string());
	}

	std::string line;
	while(std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			std::string key = line.substr(0, line.find(","));
			float value = std::stof(line.substr(line.find(",") + 1));
			_priceMap.insert({key, value});
		}
	}
	printPriceMap();
}

void BitcoinExchange::printPriceMap()
{
	for (auto& [date, price] : _priceMap)
	{
		std::cout << "entry[" << date << ", " << price << "]" << std::endl;
	}
}

float	BitcoinExchange::getPriceAtDate(const std::string& date)
{
	float price = 0.0f;

	try
	{
		price = _priceMap[date];
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return price;
}

BitcoinExchange::~BitcoinExchange()
{

}
