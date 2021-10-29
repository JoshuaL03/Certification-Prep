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
	Shape(std::string c) { color = c; count++; }
	~Shape() { count--; }

	std::string GetColor() { return color; }
	void SetColor(std::string c) { color = c; }

	static int GetCount() { return count; }
};