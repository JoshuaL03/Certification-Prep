#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
 private:
  double side;

 public:
  Square() noexcept { side = 1; }
  explicit Square(double s) noexcept : side(s){};
  Square(double s, std::string c) : Shape(c), side(s){};

  [[nodiscard]] auto GetSide() const noexcept -> double { return side; }
  void SetSide(double s) noexcept { side = s; }

  [[nodiscard]] auto CalculateArea() const noexcept -> double;
  [[nodiscard]] auto CalculatePerimeter() const noexcept -> double;
};

#endif