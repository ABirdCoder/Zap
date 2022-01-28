#include "../include/origifier.hpp"
#include <map>
#include <string>
#include <vector>


std::map<std::string, std::string> Origifier::tokenMap;


Origifier::Origifier(std::vector<std::string> tokens) {
	tokensList = tokens;
}




