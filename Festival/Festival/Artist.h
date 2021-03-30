#pragma once
#include "Event.h"

class Artist : public Event
{
private:
public:
    Artist();
    Artist(string name, string date, string place, int ticketsTotal, int ticketsBought = 0);
    Artist(const Artist& a);
    ~Artist();
    Event* clone();
    string toString(string sep);
};