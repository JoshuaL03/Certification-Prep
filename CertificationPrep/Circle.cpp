#include "Circle.h"

auto Circle::CalculateArea() const noexcept -> double {
  // The cmath header would ordinarily be included along with the
  // _USE_MATH_DEFINES to define a constant for pi, but the latter produces a
  // warning because it is a reserved identifier.
  constexpr double pi = 3.14159265358979323846;
  return pi * pow(radius, 2);
}

auto Circle::CalculateCircumference() const noexcept -> double {
  constexpr double pi = 3.14159265358979323846;
  return 2 * pi * radius;
}