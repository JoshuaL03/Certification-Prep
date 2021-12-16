#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
 private:
  // LO6
  double base;
  double height;

 public:
  Triangle() noexcept {
    base = 1;
    height = 1;
  }
  Triangle(double b, double h) noexcept : base(b), height(h){};
  // LO1c
  Triangle(double b, double h, std::string c) : Shape(c), base(b), height(h){};

  [[nodiscard]] auto GetBase() const noexcept -> double { return base; }
  void SetBase(double b) noexcept { base = b; }

  [[nodiscard]] auto GetHeight() const noexcept -> double { return height; }
  void SetHeight(double h) noexcept { height = h; }

  [[nodiscard]] auto CalculateArea() const noexcept -> double;
  // The perimeter cannot be calculated only given base and height
};

#endif