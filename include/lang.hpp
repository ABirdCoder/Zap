#pragma once
#include <string>
#include <vector>

class ZapLang {
public:
  static std::string CompileLine(std::string line);
	static std::vector<std::string> Compile(std::string filePath);
private:
  ZapLang();  
};


