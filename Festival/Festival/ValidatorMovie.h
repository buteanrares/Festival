#pragma once
#include "ValidatorEvent.h"
#include "ValidationException.h"
#include "Movie.h"

class ValidatorMovie : public ValidatorEvent
{
public:
	ValidatorMovie();
	~ValidatorMovie();
	void validate(Event* e);
};