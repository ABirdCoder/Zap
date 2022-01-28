#include <iostream>
#include <string>
#include <vector>
#include "../include/lang.hpp"



int main() {
  std::vector<std::string> output = ZapLang::Compile("../main.zap");

	for (std::string s : output) {
		std::cout << s;
	}
} 