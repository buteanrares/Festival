#include "ValidatorMovie.h"
ValidatorMovie::ValidatorMovie()
{
}

ValidatorMovie::~ValidatorMovie()
{
}

void ValidatorMovie::validate(Event* p)
{
	ValidatorEvent::validate(p);
	Movie* m = (Movie*)p;
	if (m->getCast().size() < 1)
	{
		throw ValidationException("A movie cannot be made without actors.");
	}
}