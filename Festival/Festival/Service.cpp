#include "Service.h"
Service::Service()
{
}

Service::~Service()
{
}

Service::Service(Repo* repo)
{
    this->repo = repo;
}

deque<Event*> Service::getAll()
{
    return this->repo->getAll();
}

deque<Event*> Service::getEventsByDate(string date) {
    deque<Event*> events = this->repo->getAll();
    deque<Event*> out;
    for (int i = 0; i < events.size(); i++) {
        if (events[i]->getDate() == date) {
            out.push_back(events[i]->clone());
        }
    }
    return out;
}

//MODIF
Event* Service::readEvent(int pos) // throw(RepoException)
{
    return this->repo->readEvent(pos);
}

void Service::addArtist(string name, string date, string place, int ticketsTotal,int ticketsBought) // throw(ValidationException, RepoException)
{
    ticketsBought = 0;
    Artist* a = new Artist(name, date, place, ticketsTotal,ticketsBought);
    this->repo->addEvent(a);
}

void Service::addMovie(string name, string date, string place, int ticketsTotal, int ticketsBought, int castSize, vector<string> cast) // throw(ValidationException, RepoException)
{
    ticketsBought = 0;
    Movie* m = new Movie(name, date, place, ticketsTotal, ticketsBought, castSize,cast);
    this->repo->addEvent(m);
}

void Service::updateArtist(string oldName, string newName, string date, string place, int ticketsTotal, int ticketsBought) // throw(ValidationException, RepoException)
{
    Event* oldArtist = new Artist(oldName, "date", "place", 0);
    Artist* newArtist = new Artist(newName, date, place, ticketsTotal, ticketsBought);
    this->repo->updateEvent(oldArtist, newArtist);
}

void Service::updateMovie(string oldName, string newName, string date, string place, int ticketsTotal, int ticketsBought, int castSize, vector<string> cast) // throw(ValidationException, RepoException)
{
    Event* oldMovie = new Movie(oldName, "date", "place", ticketsTotal, ticketsBought, castSize, cast);
    Movie* newMovie = new Movie(newName, date, place, ticketsTotal, ticketsBought, castSize, cast);
    this->repo->updateEvent(oldMovie, newMovie);
}

void Service::deleteEvent(string name) // throw(RepoException)
{
    Event* e = new Event(name, "date", "place", 0,0);
    this->repo->deleteEvent(e);
}

void Service::loadFromFile() // throw(ReadFromFileException)
{
    this->repo->loadFromFile();
}

void Service::saveToFile()
{
    this->repo->saveToFile();
}

void Service::setFileName(string fileName)
{
    this->repo->setFileName(fileName);
}

bool Service::login(string user, string password)
{
    if (user == "admin" && password == "admin")
        return true;
    return false;
}

int Service::buy(string name, int quantity)
{
    deque<Event*> events = this->repo->getAll();
    for (Event* e : events)
    {
        if (e->getName() == name)
            if (e->getTicketsTotal() - e->getTicketsBought() >= quantity)
            {
                e->setTicketsBought(e->getTicketsBought() + quantity);
                this->saveToFile();
                return 0;
            }
            else
            {
                e->setTicketsBought(e->getTicketsTotal());
                this->saveToFile();
                return 1;
            }
    }
    return -2;
}

void Service::setRepo(Repo* repo) {
    this->repo = repo;
}