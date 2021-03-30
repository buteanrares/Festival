#pragma once

#include "Event.h"
#include <vector>
#include <iostream>

using namespace std;

class Movie : public Event
{
private:
    vector<string> cast;
    int castSize;

public:
    Movie();
    Movie(string name, string date, string place, int ticketsTotal, int ticketsBought, int castSize, vector<string> cast);
    Movie(const Movie& m);
    ~Movie();
    Event* clone();
    vector<string> getCast();
    bool operator==(Movie const& m);
    Movie& operator=(Movie m);
    void print();
    string toString(string sep);
};
