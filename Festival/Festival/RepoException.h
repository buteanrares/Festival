#pragma once
#include <exception>
#include <string.h>

using namespace std;

class RepoException : public exception
{
private:
    char* message;

public:
    RepoException(const char* message)
    {
        this->message = new char[strlen(message) + 1];
        strcpy(this->message, message);
    }

    ~RepoException()
    {
        if (this->message != NULL)
        {
            delete[] this->message;
        }
    }

    virtual const char* what()
    {
        return message;
    }
};
