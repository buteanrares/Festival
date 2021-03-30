#include "Repo.h"
Repo::Repo()
{
}

Repo::Repo(string fileName)
{
    this->fileName = fileName;
}

Repo::~Repo()
{
    if (this->deck.size() != 0)
    {
        this->deck.clear();
    }
}

void Repo::setFileName(string fileName)
{
    this->fileName = fileName;
}

void Repo::addEvent(Event* e) // throw(ValidationException, RepoException)
{
    if (typeid(*e) == typeid(Artist))
    {
        this->validatorA.validate(e);
    }
    else if (typeid(*e) == typeid(Movie))
    {
        this->validatorM.validate(e);
    }

    if (this->readEvent(e) != NULL)
        throw RepoException("You cannot add duplicates");
    this->deck.push_back(e->clone());
    this->saveToFile();
}

void Repo::updateEvent(Event* oldEvent, Event* newEvent)
{
    if (typeid(*newEvent) == typeid(Artist)) {
        this->validatorA.validate(newEvent);
    }
    if (typeid(*newEvent) == typeid(Movie)) {
        this->validatorM.validate(newEvent);
    }
    if (this->readEvent(oldEvent) == NULL) {
        throw RepoException("No event with that name");
    }
    for (int i = 0; i < this->deck.size(); i++)
    {
        if (this->readEvent(i)->getName() == oldEvent->getName()) {
            delete this->deck[i];
            this->deck[i] = newEvent->clone();
            this->saveToFile();
            return;
        }
    }
}

Event* Repo::readEvent(Event* event)
{
    for (int i = 0; i < this->deck.size(); i++)
    {
        if (this->deck[i]->getName() == event->getName())
            return this->deck[i]->clone();
    }
    return NULL;
}

Event* Repo::readEvent(int pos) // throw(ValidationException, RepoException)
{
    if (pos >= 0 && pos < this->getSize())
    {
        return this->deck[pos]->clone();
    }
    throw RepoException("Invalid index.");
}

void Repo::deleteEvent(Event* event)
{
    for (int i = 0; i < this->deck.size(); i++) {
        if (this->deck[i]->getName() == event->getName()) {
            delete this->deck[i];
            this->deck.erase(this->deck.begin() + i);
            this->saveToFile();
            return;
        }
    }
    throw RepoException("No event with that name.");
}

deque<Event*> Repo::getAll()
{
    return this->deck;
}

int Repo::getSize()
{
    return this->deck.size();
}

Repo& Repo::operator=(Repo& r)
{
    this->deck = r.deck;
    if (r.fileName.length())
    {
        this->fileName = r.fileName;
    }
    else
    {
        this->fileName = nullptr;
    }
    return *this;
}

Repo::Repo(Repo& r)
{
    this->deck = r.deck;
    if (r.fileName.length())
    {
        this->fileName = r.fileName;
    }
    else
    {
        this->fileName = nullptr;
    }
}
