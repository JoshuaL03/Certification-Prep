#include "Circle.h"

auto Circle::CalculateArea() const noexcept -> double {
	return M_PI * pow(radius, 2);
}

auto Circle::CalculateCircumference() const noexcept -> double {
	return 2 * M_PI * radius;
}