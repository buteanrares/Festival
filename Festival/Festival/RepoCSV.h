#pragma once
#include "Repo.h"
#include "Artist.h"
#include "Movie.h"

class RepoCSV : public Repo
{
private:
public:
    RepoCSV();
    RepoCSV(string filename);
    ~RepoCSV();
    void loadFromFile();
    void saveToFile();
};

