#pragma once
#include "Person.h"
#include <iostream>

class Flat
{
   
    Person* persons;
    int PersonsCount;
    void _addPersonPlace();
public:
    Flat() : persons{ nullptr }, PersonsCount{ 0 } {};


    Flat(const Flat& object);
    Flat(Flat&& object);

    Flat& operator=(const Flat& object);
    Flat& operator=(Flat&& object);

    Flat& addPerson(const Person& object);
    Flat& addPerson(Person&& object);

    friend std::ostream& operator<<(std::ostream& out, const Flat& object);

    ~Flat() { delete[] persons; }
};

