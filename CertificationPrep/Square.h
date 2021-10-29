#pragma once
#include "Shape.h"

class Square : public Shape
{
private:
	double side;

public:
	Square() { side = 1; }
	Square(double s) { side = s; }
	Square(double s, std::string c) : Shape(c), side(s) {};

	double GetSide() { return side; }
	void SetSide(double s) { side = s; }

	double CalculateArea();
	double CalculatePerimeter();
};

