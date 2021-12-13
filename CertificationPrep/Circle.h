#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// Classes inherited in public visibility mode have their public members visible to all,
// their protected members visible to the derived class, and their private members invisible to all

// Classes inherited in protected visibility mode have their public and protected members visible
// to the derived class, and their private members invisible to all

// Classes inherited in private visibility mode have their public and protected members visible
// only to the directly derived class (they become private members of that class),
// and private members invisible to all

class Circle : public Shape
{
private:
	double radius;

public:
	Circle() noexcept{ radius = 1; }
	explicit Circle(double r) noexcept { radius = r; }
	Circle(double r, std::string c) : Shape(c), radius(r) {};

	auto GetRadius() const noexcept -> double { return radius; }
	void SetRadius(double r) noexcept { radius = r; }

	auto CalculateArea() const noexcept -> double;
	auto CalculateCircumference() const noexcept-> double;
};

#endif