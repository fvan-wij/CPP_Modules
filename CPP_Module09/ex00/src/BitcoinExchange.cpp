#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>

std::chrono::system_clock::time_point	BitcoinExchange::stringToDate(const std::string& dateStr)
{
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    
    if (ss.fail())
	{
        throw std::invalid_argument("Invalid date format");
    }

    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;

}

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
			double value = std::stod(line.substr(line.find(",") + 1));
			_priceMap.insert({stringToDate(key), value});
		}
	}
	// printPriceMap();
}

void BitcoinExchange::printPriceMap()
{
	for (const auto& [date, value] : _priceMap) {
		std::time_t time = std::chrono::system_clock::to_time_t(date);
		std::tm tm = *std::localtime(&time);
		std::ostringstream date_stream;
		date_stream << std::put_time(&tm, "%Y-%m-%d");
		std::string date_str = date_stream.str();
		std::cout << "Date: " << date_str << " -> Value: " << value << std::endl;
	}
}

std::optional<double>	BitcoinExchange::getPriceAtDate(const std::string& date)
{
	auto tpDate = stringToDate(date);

	if (_priceMap.find(tpDate) != _priceMap.end())
	{
		return _priceMap.at(tpDate);
	}

	if (tpDate < _priceMap.begin()->first)
	{
		std::cout << "Under lower bounds" << std::endl;
		return _priceMap.begin()->second;
	}
	else if (tpDate > _priceMap.rbegin()->first)
	{
		std::cout << "Over upper bounds" << std::endl;
		return _priceMap.rbegin()->second;
	}

	auto it = _priceMap.lower_bound(tpDate);
	if (it != _priceMap.end())
	{
		it--;
		return it->second;
	}
	else
	{
		return std::nullopt;
	}
}

BitcoinExchange::~BitcoinExchange()
{

}
