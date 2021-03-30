#pragma once
#include "Movie.h"
#include <cassert>
#include <cstring>

class TestMovie
{
private:
    void test_getters();
    void test_setters();
    void test_constructors();
    void test_operators();

public:
    TestMovie();
    ~TestMovie();
    void test_all();
};