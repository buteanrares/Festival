#pragma once
#include "Event.h"
#include <cstring>
#include <cassert>

class TestEvent
{
private:
    void test_getters();
    void test_setters();
    void test_constructors();
    void test_operators();

public:
    TestEvent();
    ~TestEvent();
    void test_all();
};