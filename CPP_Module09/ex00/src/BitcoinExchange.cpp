#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const std::filesystem::path& exchangeDataPath)
{
	parseExchangeData(exchangeDataPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _priceMap(other._priceMap)
{
	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;

	this->_priceMap = other._priceMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::printPriceMap()
{
	for (const auto& [date, value] : _priceMap)
	{
		std::time_t time = std::chrono::system_clock::to_time_t(date);
		std::tm tm = *std::localtime(&time);
		std::stringstream date_stream;
		date_stream << std::put_time(&tm, "%Y-%m-%d");
		std::string date_str = date_stream.str();
		std::cout << "Date: " << date_str << " -> Value: " << value << std::endl;
	}
}

void	BitcoinExchange::parseExchangeData(const std::filesystem::path& path)
{
	if (path.extension() != ".csv")
	{
		throw std::invalid_argument("Incorrect extension: " + path.extension().string());
	}

	std::ifstream file(path);

	if (not file.good())
	{
		throw std::runtime_error("Error opening file: " + path.filename().string());
	}

	std::string line;
	while(std::getline(file, line))
	{
		if (line != "date,exchange_rate" && not line.empty())
		{
			std::string key = line.substr(0, line.find(","));
			double value = std::stod(line.substr(line.find(",") + 1));
			auto timePoint = stringToDate(key);
			_priceMap.insert({timePoint, value});
		}
	}
}

std::optional<std::map<std::chrono::system_clock::time_point, double>> BitcoinExchange::getPriceMap()
{
	if (_priceMap.empty())
	{
		return std::nullopt;
	}

	return _priceMap;
}

std::optional<double>	BitcoinExchange::getPriceAtDate(const std::string& date)
{
	auto tpDate = stringToDate(date); // tp == time_point (std::chrono)

	if (_priceMap.find(tpDate) != _priceMap.end()) // Is present
	{
		return _priceMap.at(tpDate);
	}

	if (tpDate < _priceMap.begin()->first) // Is past lowest entry
	{
		return _priceMap.begin()->second;
	}
	else if (tpDate > _priceMap.rbegin()->first) // Is past highest entry
	{
		return _priceMap.rbegin()->second;
	}

	auto it = _priceMap.lower_bound(tpDate); // Nearest-lowest entry
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

std::chrono::system_clock::time_point	BitcoinExchange::stringToDate(const std::string& dateStr)
{
    std::tm tm = {};
    std::stringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    
    if (ss.fail())
	{
        throw std::invalid_argument("Invalid date format");
    }

    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;
}

