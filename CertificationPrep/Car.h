#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
private:
	// No fields used for this example.

public:
	auto MakeSound() -> std::string override;
};

#endif