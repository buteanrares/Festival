#include "ValidatorEvent.h"
ValidatorEvent::ValidatorEvent()
{
}

ValidatorEvent::~ValidatorEvent()
{
}

void ValidatorEvent::validate(Event* e)
{
	if (e->getName().empty())
	{
		throw ValidationException("Name must not be null");
	}
	for (char c : e->getName())
	{
		if (!isalpha(c))
		{
			throw ValidationException("Name can only contain digits");
		}
	}
	if (e->getTicketsTotal() < 0)
	{
		throw ValidationException("Total tickets must be a positive integer");
	}
}
