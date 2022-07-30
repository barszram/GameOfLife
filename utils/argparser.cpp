#include "argparser.hpp"

#include <algorithm>

Argparser::Argparser(int argc, char** argv) {
  _exec = std::string(argv[0]);
  if (argc > 1) {
    _args.resize(argc - 1);
    for (int i = 1; i < argc; i++) {
      _args[i-1] = std::string(argv[i]);
    }
  }
}

Argparser::Arglist::size_type Argparser::arguments_amount() const {
  return _args.size();
}

bool Argparser::exists(const std::string& arg) const {
  return std::find(begin(), end(), arg) != end();
}

std::string const& Argparser::operator[](unsigned int i) const {
  return _args.at(i);
}

std::string Argparser::executable() const {
  return _exec;
}

Argparser::Arglist::const_iterator Argparser::end() const {
  return _args.end();
}

Argparser::Arglist::const_iterator Argparser::begin() const {
  return _args.begin();
}
