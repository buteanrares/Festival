#pragma once
#include "ValidatorEvent.h"
#include "Artist.h"
#include "ValidationException.h"

class ValidatorArtist : public ValidatorEvent
{
public:
	ValidatorArtist();
	~ValidatorArtist();
	void validate(Event* e);
};