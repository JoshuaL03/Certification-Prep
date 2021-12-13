#ifndef JET_H
#define JET_H

#include "Vehicle.h"

class Jet : public Vehicle
{
private:
	// No fields used for this example.

public:
	auto MakeSound() -> std::string override;
};

#endif