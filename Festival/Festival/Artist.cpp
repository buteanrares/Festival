#include "Artist.h"
Artist::Artist() : Event()
{
}

Artist::Artist(string name, string date, string place, int ticketsTotal, int ticketsBought) : Event(name, date, place, ticketsTotal, ticketsBought)
{
}

Artist::Artist(const Artist& a) : Event(a)
{
}

Artist::~Artist()
{
}

Event* Artist::clone()
{
    return new Artist(this->name, this->date, this->place, this->ticketsTotal);
}

string Artist::toString(string sep){
    return "A" + sep + Event::toString(sep);
}