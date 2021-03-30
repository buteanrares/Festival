#pragma once
#include <string>
#include "Event.h"
#include "ValidationException.h"

using namespace std;

class ValidatorEvent
{
public:
	ValidatorEvent();
	~ValidatorEvent();
	virtual void validate(Event* e);
};