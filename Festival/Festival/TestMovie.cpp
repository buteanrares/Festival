#include "TestMovie.h"
TestMovie::TestMovie()
{
}

TestMovie::~TestMovie()
{
}

void TestMovie::test_getters()
{
    Movie defaultMovie;
    assert(defaultMovie.getName() == "noname");
    assert(defaultMovie.getDate() == "nodate");
    assert(defaultMovie.getPlace() == "noplace");
    assert(defaultMovie.getTicketsBought() == 0);
    assert(defaultMovie.getTicketsTotal() == 0);
}

void TestMovie::test_setters()
{
    Movie defaultMovie;
    defaultMovie.setDate("newdate");
    defaultMovie.setPlace("newplace");
    defaultMovie.setName("newtitle");
    defaultMovie.setTicketsTotal(100);
    defaultMovie.setTicketsBought(20);
    assert(defaultMovie.getName() == "newtitle");
    assert(defaultMovie.getDate() == "newdate");
    assert(defaultMovie.getPlace() == "newplace");
    assert(defaultMovie.getTicketsTotal() == 100);
    assert(defaultMovie.getTicketsBought() == 20);
}

void TestMovie::test_constructors()
{
    vector<string> cast{ "test" };
    Movie customMovie("title", "date", "place", 100,0,1, cast);
    Movie copyMovie1(customMovie);
    Movie copyMovie2;
    copyMovie2 = customMovie;
    assert(customMovie.getName() == "title");
    assert(copyMovie1.getDate() == "date");
    assert(copyMovie2.getPlace() == "place");
}

void TestMovie::test_operators()
{
    vector<string> cast1{ "test1" };
    vector<string>cast2{ "test2" };
    Movie customMovie("title1", "date1", "place1", 100,0,1,cast1);
    Movie customMovie2("title2", "date2", "place2", 200, 1, 1, cast2);
    Movie copyMovie(customMovie);
    assert(!(customMovie == customMovie2));
    assert(customMovie == copyMovie);
}

void TestMovie::test_all()
{
    test_constructors();
    test_getters();
    test_setters();
    test_operators();
}