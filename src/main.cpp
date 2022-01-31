#include <iostream>
#include <string>
#include <vector>
#include "../include/lang.hpp"
#include "../include/stringMap.hpp"
		

int main(int argc, char* argv[]) {	
	StringMap::addStringToken("+", "PLS", "OPR");
	
  std::vector<std::string> output = ZapLang::Compile("./main.zap");

	for (std::string s : output) {
		std::cout << s + "\n";
	}
} 