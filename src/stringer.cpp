#include <map>
#include <string>
#include <vector>
#include <sstream>
#include "../include/stringer.hpp"
#include "../include/stringMap.hpp"



std::vector<std::string> Stringer::Stringify(std::string string) {
  std::vector<std::string> finalString;

  std::string lastStr;
  std::vector<std::string> mostLikely;
  bool canStop = true;
  for (char c : string) {
    if (c == ' ') {
      lastStr = "";
      canStop = true;

      if (mostLikely.size() != 0) {
        finalString.push_back(mostLikely[0] + ":" + mostLikely[1]);
      }
      else {
        // Error time!
      }

      mostLikely.clear();

      continue;
    }

    std::stringstream ss;
    std::string str;

    ss << c;

    ss >> str;

    str = lastStr + str;

    std::vector<std::string> info = StringMap::getStringToken(str);


    if (info[1] == "UNK") {
      lastStr += info[0][info[0].length() - 1];
      canStop = false;
      continue;
    }
    else {
      if (!canStop) {
        lastStr += str[str.length() - 1];
        mostLikely = info;
        continue;
      }
    }


    finalString.push_back(info[0] + ":" + info[1]);
  }

  if (mostLikely.size() != 0) {
    finalString.push_back(mostLikely[0] + ":" + mostLikely[1]);
  }
  
  return finalString;
}

