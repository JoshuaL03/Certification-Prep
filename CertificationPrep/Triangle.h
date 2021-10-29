#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	double base;
	double height;

public:
	Triangle() : base(1), height(1) {};
	Triangle(double b, double h) : base(b), height(h) {};
	Triangle(double b, double h, std::string c) : Shape(c), base(b), height(h) {};

	double GetBase() { return base; }
	void SetBase(double b) { base = b; }

	double GetHeight() { return height; }
	void SetHeight(double h) { height = h; }

	double CalculateArea();
	// The perimeter cannot be calculated only given base and height
};

