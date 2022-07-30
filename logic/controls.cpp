#include "controls.hpp"
#include <spdlog/spdlog.h>

bool Controls::addKey(const std::string& keyName, int keyCode) {
  auto keyAdded = _keys.insert({keyName, keyCode}).second;
  spdlog::info("[Controls] Trying to add new key '{0}' with code 0x{1:x}. Success? {2}.", keyName, keyCode,
               keyAdded ? "Yes" : "No");
  return keyAdded;
}

bool Controls::removeKey(const std::string& keyName) {
  auto keyErased = _keys.erase(keyName) == 1;
  spdlog::info("[Controls] Trying to remove the key '{0}'. Success? {1}.", keyName, keyErased ? "Yes" : "No");
  return keyErased;
}

bool Controls::changeKey(const std::string& keyName, int newKeyCode) {
  spdlog::info("[Controls] Trying to change the key '{0}' to 0x{1:x}", keyName, newKeyCode);
  auto elem = _keys.find(keyName);
  if (elem != _keys.end()) {
    elem->second = newKeyCode;
    spdlog::info("Key changed to 0x{0:x}", elem->second);
    return true;
  }
  spdlog::info("Key not found.");
  return false;
}

int Controls::getKeyCode(const std::string& keyName) const {
  auto elem = _keys.find(keyName);
  if (elem != _keys.end()) {
    return elem->second;
  }
  return int{};
}

int Controls::operator[](const std::string& keyName) const {
  return getKeyCode(keyName);
}
