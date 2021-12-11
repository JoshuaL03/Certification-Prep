#pragma once
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

// The procedural/functional approach uses functions to handle data, while the 
// object-oriented approach uses objects to contain and handle data (encapsulation). 
// Unlike the procedural approach, the object-oriented approach also features access
// specifiers, which allows for information hiding and more secure code.

class Shape
{
protected:
	std::string color;
	static int count;

public:
	Shape() { color = "black"; count++; }
	explicit Shape(std::string c) { color = c; count++; }

	// Define all five special member functions to follow the rule of five
	~Shape() { count--; }
	Shape(const Shape&) = delete;
	Shape(Shape&&) = delete;
	auto operator=(const Shape&) -> Shape& = delete;
	auto operator=(Shape&&) -> Shape& = delete;

	auto GetColor() -> std::string { return color; }
	void SetColor(std::string c) { color = c; }

	static int GetCount() { return count; }
};