#include "Console.h"

Console::Console()
{
}

Console::Console(Service serv)
{
    this->serv = serv;
}

Console::~Console()
{
}

void Console::_printMenu()
{
    cout << "\n1. Add artist\n";
    cout << "2. Add movie\n";
    cout << "3. Update artist\n";
    cout << "4. Update movie\n";
    cout << "5. Delete event\n";
    cout << "6. Show all events\n";
    cout << "7. Search by date\n";
    cout << "8. Buy ticket\n";
    cout << "9. Log out\n";
    cout << "10. Exit application\n";
}

void Console::_loginPrompt()
{
    string username, password;
    while (true)
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (this->serv.login(username, password))
        {
            cout << "\nLogged in successfully.\n";
            break;
        }
        else
            cout << "\nIncorrect credentials.\n";
    }
}

void Console::_requestRepoType()

{
    string format;
    cout << "\nSelect the repository format you want to use.\n";
    cout << "Type txt or csv.\n\n";
    cin >> format;
    while (true)
    {
        if (format == "txt")
        {
            this->serv.setRepo(new RepoTXT("EventRepo.txt"));
            this->serv.loadFromFile();
            break;
        }
        if (format == "csv")
        {
            this->serv.setRepo(new RepoCSV("EventRepo.csv"));
            this->serv.loadFromFile();
            break;
        }
        cout << "Incorrect format. Type txt or csv.\n";
        cin >> format;
    }
}

void Console::_handleAddArtist()
{
    string buffer;
    getline(cin, buffer);

    cout << "Name: ";
    string name;
    getline(cin,name);

    cout << "Date: ";
    string date;
    getline(cin, date);

    cout << "Place: ";
    string place;
    getline(cin, place);

    cout << "Tickets available: ";
    int ticketsTotal;
    cin >> ticketsTotal;

    int ticketsBought = 0;

    try
    {
        this->serv.addArtist(name, date, place, ticketsTotal, ticketsBought);
    }
    catch (ValidationException& e)
    {
        cout << e.what() << endl;
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
}

void Console::_handleAddMovie()
{   
    string buffer;
    getline(cin, buffer);

    cout << "Name: ";
    string name;
    cin.clear();
    cin.sync();
    getline(cin, name);

    cout << "Date: ";
    string date;
    cin.clear();
    cin.sync();
    getline(cin, date);

    cout << "Place: ";
    string place;
    cin.clear();
    cin.sync();
    getline(cin, place);

    cout << "Tickets available: ";
    int ticketsTotal;
    cin >> ticketsTotal;

    vector<string> cast;
    cout << "Cast size: ";
    int castNr;
    cin >> castNr;

    string buffer2;
    getline(cin, buffer2);

    for (int i = 0; i < castNr; i++)
    {
        cout << "Actor name: ";
        string actorName;
        cin.clear();
        cin.sync();
        getline(cin, actorName);
        cast.push_back(actorName);
    }

    try
    {
        this->serv.addMovie(name, date, place, ticketsTotal, 0, castNr, cast);
    }
    catch (ValidationException& e)
    {
        cout << e.what() << endl;
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
}

void Console::_handleUpdateArtist()
{
    string buffer;
    getline(cin, buffer);

    cout << "Name the artist you want to update: ";
    string oldName;
    cin.clear();
    cin.sync();
    getline(cin, oldName);

    cout << "New name: ";
    string newName;
    cin.clear();
    cin.sync();
    getline(cin, newName);

    cout << "New date: ";
    string newDate;
    cin.clear();
    cin.sync();
    getline(cin, newDate);

    cout << "New place: ";
    string newPlace;
    cin.clear();
    cin.sync();
    getline(cin, newPlace);

    cout << "New tickets available: ";
    int ticketsTotal;
    cin >> ticketsTotal;

    cout << "New tickets bought: ";
    int ticketsBought;
    cin >> ticketsBought;

    try
    {
        this->serv.updateArtist(oldName, newName, newDate, newPlace, ticketsTotal, ticketsBought);
    }
    catch (ValidationException& e)
    {
        cout << e.what() << endl;
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
}

void Console::_handleUpdateMovie()
{
    string buffer;
    getline(cin, buffer);

    cout << "Name the movie you want to update: ";
    string oldName;
    cin.clear();
    cin.sync();
    getline(cin, oldName);

    cout << "New name: ";
    string newName;
    cin.clear();
    cin.sync();
    getline(cin, newName);

    cout << "New date: ";
    string newDate;
    cin.clear();
    cin.sync();
    getline(cin, newDate);

    cout << "New place: ";
    string newPlace;
    cin.clear();
    cin.sync();
    getline(cin, newPlace);

    cout << "New tickets available: ";
    int ticketsTotal;
    cin >> ticketsTotal;

    cout << "New tickets bought: ";
    int ticketsBought;
    cin >> ticketsBought;

    cout << "New cast size: ";
    int castNr;
    cin >> castNr;
    vector<string> cast;

    string buffer2;
    getline(cin, buffer2);

    for (int i = 0; i < castNr; i++)
    {
        string actorName;
        cout << "Actor name: ";
        cin.clear();
        cin.sync();
        getline(cin, actorName);
        cast.push_back(actorName);
    }

    try
    {
        this->serv.updateMovie(oldName, newName, newDate, newPlace, ticketsTotal, ticketsBought, castNr, cast);
    }
    catch (ValidationException& e)
    {
        cout << e.what() << endl;
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
}

void Console::_handleDeleteEvent()
{
    string buffer;
    getline(cin, buffer);

    cout << "Name the event you want to remove: ";
    string name;
    cin.clear();
    cin.sync();
    getline(cin, name);
    try
    {
        this->serv.deleteEvent(name);
    }
    catch (RepoException& e)
    {
        cout << e.what() << endl;
    }
}

void Console::_handleShowAll()
{
    this->_printEvents(this->serv.getAll());
}

void Console::_printEvents(deque<Event*> events)
{
    for (Event* e : events)
    {
        cout << e->toString(" ") << endl;
    }
}

void Console::_handleSearchByDate() {
    string buffer;
    getline(cin, buffer);
    
    string date;
    cout << "Date to search by: ";
    getline(cin, date);
    this->_printEvents(this->serv.getEventsByDate(date));
}

void Console::_handleBuyTickets() {
    string buffer;
    getline(cin, buffer);

    string eventName;
    cout << "Event name: ";
    getline(cin, eventName);

    int nrTickets;
    cout << "Number of tickets: ";
    cin >> nrTickets;

    int status = this->serv.buy(eventName, nrTickets);
    if (status == 0) {
        cout << "Purchase complete\n";
        return;
    }
    if (status == -1) {
        cout << "Not enough available tickets\n";
        return;
    }
    if (status == 1) {
        cout << "Limit succedeed, but ...\n";
        return;
    }
    cout << "No event with that name\n";
}

void Console::run()
{
LogOutFlag:
    this->_loginPrompt();
    this->_requestRepoType();
    this->_printMenu();
    int op = 0;
    while (op != 10)
    {
        cout << "\nSelect option: ";
        cin >> op;
        if (op == 1)
            this->_handleAddArtist();
        else if (op == 2)
            this->_handleAddMovie();
        else if (op == 3)
            this->_handleUpdateArtist();
        else if (op == 4)
            this->_handleUpdateMovie();
        else if (op == 5)
            this->_handleDeleteEvent();
        else if (op == 6)
            this->_handleShowAll();
        else if (op == 7)
            this->_handleSearchByDate();
        else if (op == 8)
            this->_handleBuyTickets();
        else if (op == 9) {
            system("cls");
            goto LogOutFlag;
        }
    }
}
