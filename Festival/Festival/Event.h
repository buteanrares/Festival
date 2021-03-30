#pragma once
#include <string>
#include <sstream>

using namespace std;

class Event
{
protected:
    string name;
    string date;
    string place;
    int ticketsTotal;
    int ticketsBought;

public:
    Event();
    Event(string name, string date, string place, int ticketsTotal, int ticketsBought);
    Event(const Event& a);
    ~Event();

    virtual Event* clone();
    string getName();
    string getDate();
    string getPlace();
    void setName(string newName);
    void setDate(string newDate);
    void setPlace(string newPlace);
    void setTicketsTotal(int newTicketsTotal);
    void setTicketsBought(int newTicketsBought);
    int getTicketsTotal();
    int getTicketsBought();
    bool operator==(Event& a);
    Event& operator=(Event a);

    virtual string toString(string delim);
};
