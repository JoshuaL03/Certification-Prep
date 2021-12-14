#ifndef RUN_H
#define RUN_H

#include <iostream>
#include <string>

class Run
{
private:
	// An interface has no fields.

public:
	Run() = default;

	// Define all five special member functions to follow the rule of five
	virtual ~Run() = default;
	Run(const Run&) = delete;
	Run(Run&&) = delete;
	auto operator=(const Run&) -> Run& = delete;
	auto operator=(Run&&) -> Run& = delete;

	virtual void StartRunning() = 0;
	virtual void StopRunning() = 0;
};

#endif