#pragma once
#include <map>
#include <string>
#include <vector>


class StringMap {
public:
  static void addStringToken(std::string string, std::string to, std::string type);

  static std::vector<std::string> getStringToken(std::string string);

  static std::string getOriginalToken(std::vector<std::string> strings);

private:
  StringMap();

  static std::map<std::string, std::string> stringMap; 
};