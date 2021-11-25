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

	void StartRunning() {
		std::cout << "The cheetah has started running!\n";
	}
	void StopRunning() {
		std::cout << "The cheetah has stopped running!\n";
	}

	void Hunt() {
		std::cout << "The cheetah is hunting!\n";
	}
};