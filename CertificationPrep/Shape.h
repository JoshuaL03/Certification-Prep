#ifndef SHAPE_H
#define SHAPE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

// The procedural/functional approach uses functions to handle data, while the 
// object-oriented approach uses objects to contain and handle data (encapsulation). 
// Unlike the procedural approach, the object-oriented approach also features access
// specifiers, which allows for information hiding and more secure code.

class Shape
{
private:
	std::string color;
	static int count;

public:
	Shape() noexcept { color = "black"; count++; }
	explicit Shape(std::string c) { color = c; count++; }

	// Define all five special member functions to follow the rule of five
	~Shape() { count--; }
	Shape(const Shape&) = delete;
	Shape(Shape&&) = delete;
	auto operator=(const Shape&) -> Shape& = delete;
	auto operator=(Shape&&) -> Shape& = delete;

	auto GetColor() -> std::string { return color; }
	void SetColor(std::string c) { color = c; }

	static auto GetCount() noexcept -> int { return count; }
};

#endif