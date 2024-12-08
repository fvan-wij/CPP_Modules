#pragma once

#include <string>
#include <map>
#include <filesystem>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::filesystem::path& exchangeDataPath);
		~BitcoinExchange();

		void printPriceMap();
		float	getPriceAtDate(const std::string& date);

	private:
		std::map<std::string, float>	_priceMap;
};
