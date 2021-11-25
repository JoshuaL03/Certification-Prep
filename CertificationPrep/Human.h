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

	void StartRunning();
	void StopRunning();

	void WatchTV();
};