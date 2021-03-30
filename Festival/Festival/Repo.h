#pragma once

#include "Artist.h"
#include "Movie.h"
#include "ValidationException.h"
#include "ValidatorArtist.h"
#include "ValidatorMovie.h"
#include "RepoException.h"
#include <deque>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class Repo
{
protected:
    deque<Event*> deck;
    string fileName;
    ValidatorArtist validatorA;
    ValidatorMovie validatorM;

public:
    Repo();
    Repo(string fileName);
    ~Repo();

    void setFileName(string fileName);
    void addEvent(Event* event);
    void updateEvent(Event* oldEvent, Event* newEvent);
    void deleteEvent(Event* event);
    Event* readEvent(Event* event);
    Event* readEvent(int pos);
    deque<Event*> getAll();
    int getSize();
    virtual void loadFromFile() = 0;
    virtual void saveToFile() = 0;
    Repo& operator=(Repo& r);
    Repo(Repo& r);
};

