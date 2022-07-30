#pragma once

#include "../utils/list2d.hpp"
#include <functional>

enum class CellState {
  INVALID, DEAD, ALIVE
};

class CellField {
public:
  using CellList = List2D<CellState>;
  // StepCallback is called for each cell.
  // Arguments: list of cells, (x, y) coordinates of cell
  // Should return: State of the (x, y) cell
  using StepCallback = std::function<CellState(CellField const& cells, unsigned x, unsigned y)>;
  // PopulateCallback is used to populate the list of cells
  // Similar to StepCallback, it's called for each cell
  // Arguments: (x, y) coordinates of current cell
  // Should return: State of (x, y) cell
  using PopulateCallback = std::function<CellState(unsigned x, unsigned y)>;

  CellField() = default;
  CellField(unsigned width, unsigned height);

  [[nodiscard]] unsigned height() const;
  [[nodiscard]] unsigned width() const;

  void resize(unsigned width, unsigned height, bool clear = true);
  [[nodiscard]] CellState get(unsigned x, unsigned y) const;

  void populate(PopulateCallback const& populateFunc);
  void setStepCallback(const StepCallback& callback);

  void step();
  void clear();

  [[nodiscard]] bool pointInBounds(unsigned x, unsigned y) const;
  [[nodiscard]] unsigned neightbourCellsCount(unsigned x, unsigned y, CellState state = CellState::ALIVE) const;

private:
  unsigned _width{};
  unsigned _height{};
  CellList _cell_list{};
  StepCallback _step_callback{};
};

