#pragma once

#include <string>
#include <map>
#include <filesystem>
#include <optional>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::filesystem::path& exchangeDataPath);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void 	printPriceMap();
		void	parseExchangeData(const std::filesystem::path& path);

		std::optional<double>	getPriceAtDate(const std::string& date);
		std::optional<std::map<std::chrono::system_clock::time_point, double>> getPriceMap();
		std::chrono::system_clock::time_point	stringToDate(const std::string& dateStr);


	private:
		std::map<std::chrono::system_clock::time_point, double> _priceMap;
};
