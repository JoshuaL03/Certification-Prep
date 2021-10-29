#include "Circle.h"

double Circle::CalculateArea() {
	return M_PI * pow(radius, 2);
}

double Circle::CalculateCircumference() {
	return 2 * M_PI * radius;
}