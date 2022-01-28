#include "../include/stringMap.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <sstream>

std::map<std::string, std::string> StringMap::stringMap;

std::vector<std::string> split (std::string s, std::string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
      token = s.substr (pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back (token);
  }

  res.push_back (s.substr (pos_start));
  return res;
}

void StringMap::addStringToken(std::string string, std::string to, std::string type) {
  stringMap[string] = to + "-" + type;
}


std::vector<std::string> StringMap::getStringToken(std::string string) {
  if (!stringMap.count(string)) {
    std::vector<std::string> vec;
    for (char const &c : string) {
      if (std::isdigit(c) == 0) {
        vec.push_back(string);
        vec.push_back("UNK");
        return vec;
      }
    }
    vec.push_back(string);
    vec.push_back("NUM");
    return vec;
  }

  return split(stringMap[string], "-");
}

std::string StringMap::getOriginalToken(std::vector<std::string> strings) {
  //for (std::)
}