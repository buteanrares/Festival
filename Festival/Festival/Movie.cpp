#include "Movie.h"
using namespace std;

Movie::Movie() : Event()
{
}

Movie::Movie(string name, string date, string place, int ticketsTotal, int ticketsBought, int castSize, vector<string> cast) // : Event(name, date, place, ticketsTotal, ticketsBought)
{
    this->name = name;
    this->date = date;
    this->place = place;
    this->ticketsTotal = ticketsTotal;
    this->ticketsBought = ticketsBought;
    this->castSize = castSize;
    this->cast = cast;
}

Movie::Movie(const Movie& m) : Event(m)
{
}

Movie::~Movie()
{
}

Event* Movie::clone()
{
    return new Movie(this->name, this->date, this->place, this->ticketsTotal, this->ticketsBought, this->castSize, this->cast);
}

bool Movie::operator==(Movie const& m)
{
    //bool actorsFlag = true;
    //if (this->cast.size() != m.cast.size())
    //    actorsFlag = false;
    //for (int i = 0; i < this->cast.size(); i++)
    //    if (this->cast[i] != m.cast[i])
    //        actorsFlag = false;
    return this->name == m.name && this->date == m.date && this->place == m.place && this->ticketsBought == m.ticketsBought && this->ticketsTotal == m.ticketsTotal; //TODO compare cast
}

vector<string> Movie::getCast()
{
    return this->cast;
}

Movie& Movie::operator=(Movie m)
{
    this->name = m.name;
    this->date = m.date;
    this->place = m.place;
    this->ticketsTotal = m.ticketsTotal;
    this->ticketsBought = m.ticketsBought;
    for (int i = 0; i < m.cast.size(); i++)
    {
        this->cast[i] = m.cast[i];
    }
    return *this;
}

void Movie::print()
{
    cout << "Title: " << this->name
        << "\nDate: " << this->date
        << "\nPlace: " << this->place
        << "\nTickets available: " << this->ticketsTotal - this->ticketsBought
        << "\nTickets bought: " << this->ticketsBought;
    cout << "\nActors:\n      ";
    for (int i = 0; i < this->cast.size(); i++)
    {
        cout << this->cast[i] << " ";
    }
}

string Movie::toString(string sep) {
    string castToString;
    castToString.clear();

    for (vector<string>::const_iterator p = this->cast.begin();p!=this->cast.end();p++) {
        castToString += *p;
        if (p != this->cast.end() - 1) {
            castToString += sep;
        }
    }
    return "M" + sep + Event::toString(sep) + sep + to_string(this->castSize) + sep + castToString;
}
