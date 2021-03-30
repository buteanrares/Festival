#pragma once
#include "Repo.h"
#include "RepoException.h"
#include "Artist.h"
#include "Movie.h"
#include "RepoException.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
#include <algorithm>

class Service
{
private:
    Repo* repo;
    string username, password;

public:
    Service();
    Service(Repo* repo);
    ~Service();

    void addArtist(string name, string date, string place, int ticketsTotal,int ticketsBought);
    void addMovie(string name, string date, string place, int ticketsTotal,int ticketsBought, int castSize, vector<string> cast);
    void updateArtist(string oldName, string newName, string date, string place, int ticketsTotal, int ticketsBought);
    void updateMovie(string oldName, string newName, string date, string place, int ticketsTotal, int ticketsBought, int castSize, vector<string> cast);
    void deleteEvent(string name);
    Event* readEvent(int pos);

    deque<Event*> getAll();
    deque<Event*>getEventsByDate(string date);
    bool login(string username, string password);
    void loadFromFile();
    void saveToFile();
    void setFileName(string fileName);
    void setRepo(Repo* repo);

    int buy(string name, int quantity);
};