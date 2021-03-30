#pragma once
#include <string>
#include "Event.h"
#include "ValidationException.h"

using namespace std;

class EventValidator
{
public:
    EventValidator();
    ~EventValidator();
    virtual void validate(Event* e);
};