#include "../include/lang.hpp"
#include "../include/stringer.hpp"
#include "../include/origifier.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <fstream> 
#include <iostream>


std::vector<std::string> ZapLang::Compile(std::string filePath) {
	std::vector<std::string> toReturn;
	std::ifstream file(filePath);

	std::string str;

	if (!file.is_open()) {
		std::cout << "Could not open file " + filePath + ".\n";
	}
			
	while (std::getline(file, str)) {
		toReturn.push_back(CompileLine(str));
	}

	file.close();

	return toReturn;
}

std::string ZapLang::CompileLine(std::string line) {
  Stringer *stringer = new Stringer();

  std::vector<std::string> stringerOutput = stringer->Stringify(line);

	Origifier *origifier = new Origifier(stringerOutput);

	

	
  std::string output;

  for (std::string s : stringerOutput) {
    output += s + " ";
  }

  return output;
}