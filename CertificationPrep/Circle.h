#pragma once
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
	Circle() { radius = 1; }
	Circle(double r) { radius = r; }
	Circle(double r, std::string c) : Shape(c), radius(r) {};

	double GetRadius() { return radius; }
	void SetRadius(double r) { radius = r; }

	double CalculateArea();
	double CalculateCircumference();
};