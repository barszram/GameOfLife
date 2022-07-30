#pragma once
#include <vector>
#include <algorithm>
#include <utility>

template <typename T>
class List2D {
public:
  using Type = T;
  using Container = std::vector<Type>;
  using Iterator = typename Container::iterator;
  using ConstIterator = typename Container::const_iterator;
  using PointPair = std::pair<unsigned, unsigned>;

  List2D() = default;
  List2D(unsigned width, unsigned height) {
    resize(width, height);
  }

  void resize(unsigned width, unsigned height) {
    _width = width;
    _height = height;
    _data.resize(_width*_height);
  }

  [[nodiscard]] unsigned width() const {
    return _width;
  }

  [[nodiscard]] unsigned height() const {
    return _height;
  }

  Type& get(unsigned x, unsigned y) {
    return _data.at(XYToIndex(x, y));
  }

  Type const& get(unsigned x, unsigned y) const {
    return _data.at(XYToIndex(x, y));
  }

  Type operator[](PointPair const& coordinates) const {
    return _data[XYToIndex(coordinates.first, coordinates.second)];
  }

  void set(unsigned x, unsigned y, Type const& value) {
    _data.at(XYToIndex(x, y)) = value;
  }

  Iterator begin() {
    return _data.begin();
  }

  Iterator end() {
    return _data.end();
  }

  ConstIterator begin() const {
    return _data.begin();
  }

  ConstIterator end() const {
    return _data.end();
  }

  void clear() {
    std::fill(begin(), end(), Type{});
  }

  void fill(Type const& value) {
    std::fill(begin(), end(), value);
  }

private:
  // Assuming that (0, 0) is bottom-left corner
  [[nodiscard]] unsigned XYToIndex(unsigned x, unsigned y) const {
    return (y*_width)+x;
  }

  unsigned _width{};
  unsigned _height{};
  Container _data{};
};

