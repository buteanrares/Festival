#include "TestEvent.h"
using namespace std;

TestEvent::TestEvent()
{
}

TestEvent::~TestEvent()
{
}

void TestEvent::test_getters()
{
    Event customEvent("name", "14/05/2000", "Oradea", 100,0);
    assert(customEvent.getName() == "name");
    assert(customEvent.getDate() == "14/05/2000");
    assert(customEvent.getPlace() == "Oradea");
    assert(customEvent.getTicketsTotal() == 100);
    assert(customEvent.getTicketsBought() == 0);
}

void TestEvent::test_setters()
{
    Event customEvent("name", "14/05/2000", "Oradea", 100,0);
    customEvent.setName("newname");
    customEvent.setDate("newdate");
    customEvent.setPlace("newplace");
    customEvent.setTicketsTotal(200);
    customEvent.setTicketsBought(20);
    assert(customEvent.getName() == "newname");
    assert(customEvent.getDate() == "newdate");
    assert(customEvent.getPlace() == "newplace");
    assert(customEvent.getTicketsTotal() == 200);
    assert(customEvent.getTicketsBought() == 20);
}

void TestEvent::test_constructors()
{
    Event defaultEvent;
    Event customEvent("name", "14/05/2000", "Oradea", 100,0);
    Event copyEvent1(customEvent);
    Event copyEvent2;
    copyEvent2 = customEvent;
    assert(defaultEvent.getName() == "noname");
    assert(copyEvent1.getDate() == "14/05/2000");
    assert(copyEvent2.getName() == "name");
}

void TestEvent::test_operators()
{
    Event defaultEvent1;
    Event defaultEvent2;
    assert(defaultEvent1 == defaultEvent2);
    Event customEvent("name", "14/05/2000", "Oradea", 100,0);
    assert(!(defaultEvent1 == customEvent));
}

void TestEvent::test_all()
{
    test_constructors();
    test_getters();
    test_setters();
    test_operators();
}