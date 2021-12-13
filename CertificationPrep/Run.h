#ifndef RUN_H
#define RUN_H

#include <iostream>
#include <string>

class Run
{
private:
	// An interface has no fields.

public:
	virtual void StartRunning() = 0;
	virtual void StopRunning() = 0;
};

#endif