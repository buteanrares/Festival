// Festival.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TestEvent.h"
#include "TestMovie.h"
#include "TestRepo.h"
#include "Repo.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "Console.h"

using namespace std;

int main()
{
    // tests
    TestEvent testartist;
    testartist.test_all();

    TestMovie testmovie;
    testmovie.test_all();

    TestRepo testrepo;
    testrepo.testAll();

    Console ui;
    ui.run();

    return 0;
}