#pragma once
#include <iostream>
#include <string>

class Vehicle
{
private:
	// No fields used for this example.

public:
	virtual std::string MakeSound() {
		return "Beep!\n";
	}
};