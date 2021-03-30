#include "ValidatorArtist.h"
ValidatorArtist::ValidatorArtist()
{
}

ValidatorArtist::~ValidatorArtist()
{
}

void ValidatorArtist::validate(Event* e)
{
	ValidatorEvent::validate(e);
	// Artist does not have any other characteristics than Event
	// Event validation is already covered.
}
