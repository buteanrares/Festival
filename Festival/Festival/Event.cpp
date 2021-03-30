#include "Event.h"

using namespace std;

Event::Event()
{
    this->name = "noname";
    this->date = "nodate";
    this->place = "noplace";
    this->ticketsBought = 0;
    this->ticketsTotal = 0;
}

Event::Event(string name, string date, string place, int ticketsTotal, int ticketsBought)
{
    this->name = name;
    this->date = date;
    this->place = place;
    this->ticketsTotal = ticketsTotal;
    this->ticketsBought = ticketsBought;
}

Event::Event(const Event& e)
{
    this->name = e.name;
    this->date = e.date;
    this->place = e.place;
    this->ticketsTotal = e.ticketsTotal;
    this->ticketsBought = e.ticketsBought;
}

Event::~Event()
{
}

Event* Event::clone()
{
    return new Event(this->name, this->date, this->place, this->ticketsTotal, this->ticketsBought);
}

string Event::getName()
{
    return this->name;
}

string Event::getDate()
{
    return this->date;
}

string Event::getPlace()
{
    return this->place;
}

int Event::getTicketsTotal()
{
    return this->ticketsTotal;
}

int Event::getTicketsBought()
{
    return this->ticketsBought;
}

void Event::setName(string newName)
{
    this->name = newName;
}

void Event::setDate(string newDate)
{
    this->date = newDate;
}

void Event::setPlace(string newPlace)
{
    this->place = newPlace;
}

void Event::setTicketsTotal(int newTicketsTotal)
{
    this->ticketsTotal = newTicketsTotal;
}

void Event::setTicketsBought(int newTicketsBought)
{
    this->ticketsBought = newTicketsBought;
}

bool Event::operator==(Event& e)
{
    return this->name == e.name && this->date == e.date && this->place == e.place && this->ticketsBought == e.ticketsBought && this->ticketsTotal == e.ticketsTotal;
}

Event& Event::operator=(Event e)
{
    this->name = e.name;
    this->date = e.date;
    this->place = e.place;
    this->ticketsBought = e.ticketsBought;
    this->ticketsTotal = e.ticketsTotal;
    return *this;
}

string Event::toString(string delim)
{
    stringstream tb;
    stringstream tt;
    tb << this->ticketsBought;
    tt << this->ticketsTotal;
    string _tb;
    string _tt;
    tb >> _tb;
    tt >> _tt;
    return this->name + delim + this->date + delim + this->place + delim + _tt + delim + _tb;
}