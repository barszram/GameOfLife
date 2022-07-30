#pragma once
#include <unordered_map>
#include <string>

class Controls {
public:
  bool addKey(std::string const& keyName, int keyCode);
  bool removeKey(std::string const& keyName);
  bool changeKey(std::string const& keyName, int newKeyCode);

  int getKeyCode(std::string const& keyName) const;
  int operator[](std::string const& keyName) const;
private:
  std::unordered_map<std::string, int> _keys;
};


