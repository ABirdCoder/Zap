#pragma once
#include <map>
#include <string>
#include <vector>

class Origifier {
public:
	Origifier(std::vector<std::string> tokens);
private:
	std::vector<std::string> tokensList;
	static std::map<std::string, std::string> tokenMap;
};