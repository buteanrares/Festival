#pragma once
#include <cassert>
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "Artist.h"
#include "Movie.h"

using namespace std;

class TestRepo
{
private:
    const string fileNameTXT = "TestEventRepo.txt";
    const string fileNameCSV = "TestEventRepo.csv";

    vector<Event*> eventsIn;

    void testGetSize();
    void testGetAll();
    void testGetEvent();
    void testAddEvent();
    void testUpdateEvent();
    void testDeleteEvent();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();
    void testSaveToFileTXT();
    void testSaveToFileCSV();

public:
    TestRepo();
    ~TestRepo();
    void testAll();
};