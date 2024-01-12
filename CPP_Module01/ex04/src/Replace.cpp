#include "Replace.hpp"
#include <string>

Replace::Replace(std::string fileName){
	_sourceFile = fileName;	
	_targetFile = fileName.substr(0, fileName.find("."));
	_targetFile = _targetFile + ".replace";
}

Replace::~Replace(){

}

int	Replace::replacePattern(std::string s1, std::string s2){
    std::fstream   	sourceFile;
	std::ofstream 	targetFile;
	std::string		line;

    sourceFile.open(_sourceFile);
	targetFile.open(_targetFile);

	if (sourceFile.is_open() && targetFile.is_open()){
		while (std::getline(sourceFile, line)) {
			for (size_t i = 0; i < line.length(); i++) {
				if (line.compare(i, s1.length(), s1) == 0){
					targetFile << s2;
					i+= s1.length() - 1;
				}
				else if (i < line.length()){
					targetFile << line[i];
				}
			}
			targetFile << std::endl;
		}
		sourceFile.close();
		targetFile.close();
	}
	else {
		return 1;
	}
	return 0;
}
