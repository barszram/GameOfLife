#pragma once
#include <string>
#include <vector>
#include <initializer_list>
#include "cell_field.hpp"

class GameOfLife {
public:
  struct Rules {
    std::vector<unsigned> survive{};
    std::vector<unsigned> revive{};
  };

  GameOfLife();
  // Set rules with rulestring, separated with '/'
  // Rulestring patterns is [neightbour cells to survive]/[neightbour cells to revive]
  // For example, Conway's Game of Life rulestring is "23/3"
  // Will throw std::invalid_argument on incorrect rulestring
  explicit GameOfLife(std::string const& rulestring);

  // Set rules with Rules object
  // Will throw std::invalid_argument on incorrect rulestring
  explicit GameOfLife(Rules const& rules);

  bool setRules(Rules const& rules);
  bool setRules(std::string const& rulestring);
  [[nodiscard]] Rules rules() const;

  [[nodiscard]] CellField const& cellField() const;
  void populateField(CellField::PopulateCallback const& populateFunc);
  void setCellFieldSize(unsigned x, unsigned y);

  [[nodiscard]] unsigned cellFieldWidth() const;
  [[nodiscard]] unsigned cellFieldHeight() const;

  void step();
  void restart();

private:
  static constexpr auto RULESTRING_SEPARATOR = '/';
  static Rules const DEFAULT_RULES;
  CellState stepCallback(CellField const& cells, unsigned x, unsigned y);
  void setStepCallback();

  [[nodiscard]] bool cellSurvives(unsigned aliveNeightbourCount) const;
  [[nodiscard]] bool cellRevives(unsigned aliveNeightbourCount) const;

  Rules _rules{DEFAULT_RULES};
  CellField _field{};
};

