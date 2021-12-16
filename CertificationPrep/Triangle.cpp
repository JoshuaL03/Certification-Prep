#include "Triangle.h"

auto Triangle::CalculateArea() const noexcept -> double {
  // Declare 0.5 from the triangle area equation as a constexpr to avoid using a
  // magic number
  constexpr double triangleAreaConstant = 0.5;
  return triangleAreaConstant * base * height;
}