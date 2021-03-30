#include "TestRepo.h"
void TestRepo::testGetSize()
{
    Repo* repoFile = new RepoTXT();
    assert(repoFile->getSize() == 0);
    repoFile->addEvent(new Event());
    assert(repoFile->getSize() == 1);
}

void TestRepo::testGetAll()
{
    vector<string> cast{ "test" };
    Repo* repoFile = new RepoTXT();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    Movie* m = new Movie("Titanic", "18/11/1997", "Cluj", 300, 0, 1,cast);
    repoFile->addEvent(a);
    repoFile->addEvent(m);
    deque<Event*> events = repoFile->getAll();
    assert(*events[0] == *a->clone());
    assert(*events[1] == *m->clone());
}

void TestRepo::testGetEvent()
{
    Repo* repoFile = new RepoTXT();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    repoFile->addEvent(a);
    assert(*repoFile->readEvent(0) == *a->clone());
}

void TestRepo::testAddEvent()
{
    Repo* repoFile = new RepoTXT();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    repoFile->addEvent(a);
    assert(*repoFile->readEvent(0) == *a->clone());
}

void TestRepo::testUpdateEvent()
{
    Repo* repoFile = new RepoTXT();
    Artist* a1 = new Artist("rares", "14/05/2000", "Oradea", 200);
    Artist* a2 = new Artist("oana", "20/05/2000", "Oradea", 300);
    Artist* a3 = new Artist("denisa", "04/01/1999", "Oradea", 200);
    repoFile->addEvent(a1);
    repoFile->updateEvent(a3, a1);
    assert(*repoFile->readEvent(0) == *a1);
    repoFile->updateEvent(a1, a2);
    assert(*repoFile->readEvent(0) == *a2);
    repoFile->updateEvent(a2, a3);
    assert(*repoFile->readEvent(0) == *a3);
}

void TestRepo::testDeleteEvent()
{
    Repo* repoFile = new RepoTXT();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    repoFile->addEvent(a);
    Artist* a2 = new Artist("oana", "20/05/2000", "Oradea", 300);
    repoFile->addEvent(a2);
    repoFile->deleteEvent(a);
    assert(repoFile->getSize() == 1);
    assert(*repoFile->readEvent(1) == *a2);
}

void TestRepo::testLoadFromFileTXT()
{
    Repo* repoFile = new RepoTXT(this->fileNameTXT);
    repoFile->loadFromFile();

    //TODO:
    assert(repoFile->getSize() == 0);
    //
    assert(*repoFile->readEvent(0) == *this->eventsIn[0]);
    assert(*repoFile->readEvent(1) == *this->eventsIn[1]);
}

void TestRepo::testLoadFromFileCSV()
{
    Repo* repoFile = new RepoCSV(this->fileNameCSV);
    repoFile->loadFromFile();
    assert(repoFile->getSize() == this->eventsIn.size());
    assert(*repoFile->readEvent(0) == *this->eventsIn[0]);
    assert(*repoFile->readEvent(1) == *this->eventsIn[1]);
}

void TestRepo::testSaveToFileTXT()
{
    Repo* repoFile = new RepoTXT(this->fileNameTXT);
    repoFile->loadFromFile();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    repoFile->addEvent(a);
    // repoFile->saveToFile(); method addEvent() already saves to file.
    repoFile->loadFromFile();
    //TODO:
    assert(repoFile->getSize() == 0);
    //
    deque<Event*> events = repoFile->getAll();
    for (int i = 0; i < repoFile->getSize() - 1; i++)
        assert(*events[i] == *this->eventsIn[i]);
}

void TestRepo::testSaveToFileCSV()
{
    Repo* repoFile = new RepoCSV(this->fileNameCSV);
    repoFile->loadFromFile();
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    repoFile->addEvent(a);
    repoFile->loadFromFile();
    assert(repoFile->getSize() == this->eventsIn.size() + 1);
}

TestRepo::TestRepo()
{
    Artist* a = new Artist("rares", "14/05/2000", "Oradea", 200);
    Artist* b = new Artist("oana", "20/05/2000", "Oradea", 300);
    this->eventsIn.push_back(a);
    this->eventsIn.push_back(b);
}

TestRepo::~TestRepo()
{
}

void TestRepo::testAll()
{
    this->testAddEvent();
    this->testGetSize();
    // this->testGetEvent();
    // this->testGetAll();
    // this->testUpdateEvent();
    // this->testLoadFromFileTXT();
    // this->testLoadFromFileCSV();
    // this->testSaveToFileTXT();
    // this->testSaveToFileCSV();
}
