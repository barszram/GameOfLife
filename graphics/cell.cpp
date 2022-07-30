#include "cell.hpp"

Cell::Cell(int width, int height, int borderThickness) {
  setWidth(width);
  setHeight(height);
  setBorderThickness(borderThickness);
}

Cell::Cell(int width, int height, int borderThickness, const Color& borderColor,
           const Color& fillColor) {
  setWidth(width);
  setHeight(height);
  setBorderThickness(borderThickness);
  setBorderColor(borderColor);
  setFillColor(fillColor);
}

int Cell::getWidth() const {
  return _width;
}

int Cell::getHeight() const {
  return _height;
}

int Cell::getBorderThickness() const {
  return _border_thickness;
}

void Cell::setWidth(int width) {
  _width = width;
}

void Cell::setHeight(int height) {
  _height = height;
}

void Cell::setBorderThickness(int borderThickness) {
  _border_thickness = borderThickness;
}

const Color& Cell::getBorderColor() const {
  return _border_color;
}

void Cell::setBorderColor(const Color& borderColor) {
  _border_color = borderColor;
}

const Color& Cell::getFillColor() const {
  return _fill_color;
}

void Cell::setFillColor(const Color& fillColor) {
  _fill_color = fillColor;
}

void Cell::draw(int x, int y) const {
  DrawRectangle(x, y, getWidth(), getHeight(), getFillColor());
  DrawRectangleLinesEx(
      {static_cast<float>(x),
       static_cast<float>(y),
       static_cast<float>(getWidth()),
       static_cast<float>(getHeight())},
      getBorderThickness(), getBorderColor());
}


