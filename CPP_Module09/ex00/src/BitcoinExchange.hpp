#pragma once

#include <string>
#include <map>
#include <filesystem>
#include <optional>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::filesystem::path& exchangeDataPath);
		~BitcoinExchange();


		void printPriceMap();
		std::optional<double>	getPriceAtDate(const std::string& date);
		std::chrono::system_clock::time_point	stringToDate(const std::string& dateStr);

	private:
		std::map<std::chrono::system_clock::time_point, double> _priceMap;
};
