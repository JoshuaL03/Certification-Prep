#pragma once
#include "Run.h"

class Human : public Run
{
private:
	std::string name;

public:
	Human(std::string n) : name(n) {}

	void SetName(std::string n) { name = n; }
	std::string GetName() { return name; }

	void StartRunning() {
		std::cout << name << " has started running!\n";
	}
	void StopRunning() {
		std::cout << name << " has stopped running!\n";
	}

	void WatchTV() {
		std::cout << name << " is watching TV!\n";
	}
};