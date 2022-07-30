#pragma once

#include <raylib.h>
#include "cell.hpp"
#include "../logic/cell_field.hpp"

class CellBoard {
public:
  [[nodiscard]] int getWidth() const;
  [[nodiscard]] int getHeight() const;
  [[nodiscard]] int getSpacing() const;

  [[nodiscard]] Cell const& getCellBase() const;
  [[nodiscard]] CellField const* getCellField() const;

  void setCellSpacing(int spacingPixels);
  void setCellBase(Cell cell);
  void setCellField(CellField const* cellField);

  void draw() const;

private:
  int _spacing{};
  Cell _cellBase{};
  CellField const* _field{};
};


