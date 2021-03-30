#include "RepoCSV.h"
RepoCSV::RepoCSV() : Repo()
{
}

RepoCSV::RepoCSV(string fileName) : Repo(fileName)
{
}

RepoCSV::~RepoCSV()
{
}

void RepoCSV::loadFromFile()
{
    ifstream f(this->fileName);
    if (f.is_open())
    {
        this->deck.clear();
        string line;
        string sep = ",";
        while (getline(f, line))
        {
            if (line.substr(0, 1) == "A")
            {
                line = line.erase(0, 2);

                int pos = line.find(sep);
                string name = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                string date = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                string place = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                int ticketsTotal = stoi(line.substr(0, pos));
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                int ticketsBought = stoi(line.substr(0, pos));
                line = line.erase(0, pos + 1);

                Artist* a = new Artist(name, date, place, ticketsTotal, ticketsBought);
                this->deck.push_back(a);
            }
            else if (line.substr(0, 1) == "M")
            {
                line = line.erase(0, 2);

                int pos = line.find(sep);
                string name = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                string date = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                string place = line.substr(0, pos);
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                int ticketsTotal = stoi(line.substr(0, pos));
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                int ticketsBought = stoi(line.substr(0, pos));
                line = line.erase(0, pos + 1);

                pos = line.find(sep);
                int castSize = stoi(line.substr(0, pos));
                line = line.erase(0, pos + 1);

                vector<string> cast;

                for (int i = 0; i < castSize; i++) {
                    pos = line.find(sep);
                    string actor = line.substr(0, pos);
                    line = line.erase(0, pos + 1);
                    cast.push_back(actor);
                }

                Movie* m = new Movie(name, date, place, ticketsTotal, ticketsBought, castSize, cast);
                this->deck.push_back(m);
            }
        }
        f.close();
    }
}

void RepoCSV::saveToFile()
{
    ofstream f(this->fileName);
    if (f.is_open())
    {
        for (Event* e : this->deck)
        {
            f << e->toString(",") << endl;
        }
    }
}
