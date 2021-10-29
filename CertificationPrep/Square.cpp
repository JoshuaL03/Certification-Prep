#include "Square.h"

double Square::CalculateArea() {
	return pow(side, 2);
}

double Square::CalculatePerimeter() {
	return 4 * side;
}