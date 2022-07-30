#pragma once
#include <vector>
#include <string>

class Argparser {
 public:
  using Arglist = std::vector<std::string>;

  Argparser(int argc, char** argv);

  [[nodiscard]] Arglist::size_type arguments_amount() const;
  [[nodiscard]] bool exists(std::string const& arg) const;
  std::string const& operator[](unsigned i) const;

  [[nodiscard]] std::string executable() const;

  [[nodiscard]] Arglist::const_iterator begin() const;
  [[nodiscard]] Arglist::const_iterator end() const;

 private:
  std::string _exec;
  Arglist _args{};
};