#ifndef HUMAN_H
#define HUMAN_H

#include "Run.h"

class Human : public Run
{
private:
	std::string name;

public:
	explicit Human(std::string n) : name(n) {}

	void SetName(std::string n) { name = n; }
	auto GetName() -> std::string { return name; }

	void StartRunning() override;
	void StopRunning() override;

	void WatchTV();
};

#endif