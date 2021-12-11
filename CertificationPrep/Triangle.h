#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	double base = 1;
	double height = 1;

public:
	Triangle() = default;
	Triangle(double b, double h) : base(b), height(h) {};
	Triangle(double b, double h, std::string c) : Shape(c), base(b), height(h) {};

	auto GetBase() noexcept -> double { return base; }
	void SetBase(double b) noexcept { base = b; }

	auto GetHeight() noexcept -> double { return height; }
	void SetHeight(double h) noexcept { height = h; }

	auto CalculateArea() -> double;
	// The perimeter cannot be calculated only given base and height
};

