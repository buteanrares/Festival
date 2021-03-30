#pragma once
#include <fstream>
#include "Repo.h"
#include "Artist.h"
#include "Movie.h"

class RepoTXT : public Repo
{
private:
public:
    RepoTXT();
    RepoTXT(string fileName);
    ~RepoTXT();
    void loadFromFile();
    void saveToFile();
};
