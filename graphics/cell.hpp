#pragma once
#include <raylib.h>

class Cell {
public:
  Cell() = default;
  Cell(int width, int height, int borderThickness);
  Cell(int width, int height, int borderThickness, Color const& borderColor, Color const& fillColor);

  [[nodiscard]] int getWidth() const;
  [[nodiscard]] int getHeight() const;
  [[nodiscard]] int getBorderThickness() const;
  [[nodiscard]] const Color& getBorderColor() const;
  [[nodiscard]] const Color& getFillColor() const;

  void setWidth(int width);
  void setHeight(int height);
  void setBorderThickness(int borderThickness);
  void setBorderColor(const Color& borderColor);
  void setFillColor(const Color& fillColor);

  void draw(int x, int y) const;

private:
  int _height{};
  int _width{};
  int _border_thickness{};
  Color _border_color{};
  Color _fill_color{};
};


