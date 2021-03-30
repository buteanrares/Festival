#include "EventValidator.h"
EventValidator::EventValidator() {}
EventValidator::~EventValidator() {}

void EventValidator::validate(Event* e)
{
    if (e->getName().empty())
        throw ValidationException("Name cannot be NULL");
    for (char c : e->getName())
    {
        if (!isalpha(c))
            throw ValidationException("Name must contain letters only");
    }
    if (e->getTicketsTotal() <= 0 || e->getTicketsBought() <= 0)
        throw ValidationException("Total/Bought tickets must be a positive integer.");
}
