#pragma once
#include <fstream>
#include <string>

class Replace{
	public:
		Replace(std::string fileName);
		~Replace();
		int	replacePattern(std::string s1, std::string s2);

	private:
		std::string   	_sourceFile;
		std::string 	_targetFile;
};
