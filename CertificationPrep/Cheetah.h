#pragma once
#include "Run.h"

class Cheetah : public Run
{
private:
	std::string preferredPrey;

public:
	Cheetah(std::string prey) : preferredPrey(prey) {}

	void SetPreferredPrey(std::string prey) { preferredPrey = prey; }
	std::string GetPreferredPrey() { return preferredPrey; }

	void StartRunning();
	void StopRunning();

	void Hunt();
};