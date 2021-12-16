#include "Square.h"

auto Square::CalculateArea() const noexcept -> double { return side * side; }

auto Square::CalculatePerimeter() const noexcept -> double { return 4 * side; }