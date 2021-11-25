#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	// No fields used for this example.

public:
	std::string MakeSound();
};