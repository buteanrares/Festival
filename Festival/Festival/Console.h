#pragma once

#include "Service.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
#include "RepoException.h"

class Console
{
private:
    Service serv;
    void _printMenu();
    void _loginPrompt();
    void _requestRepoType();
    void _handleAddArtist();
    void _handleAddMovie();
    void _handleUpdateArtist();
    void _handleUpdateMovie();
    void _handleDeleteEvent();
    void _handleShowAll();
    void _printEvents(deque<Event*> events);
    void _handleSearchByDate();
    void _handleBuyTickets();

public:
    Console();
    Console(Service serv);
    ~Console();
    void run();
};