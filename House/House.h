#pragma once
#include "Flat.h"
class House
{

    int flatsCount;
    Flat* flats;

public:
    House(const int flatsCountP) :flatsCount{ flatsCountP }, flats{ new Flat[flatsCountP] {} } {}
    House() : House(4) {}

    House& setFlatCount(const int flatCountP) { flatsCount = flatCountP; return *this; }

    const int getFlatCount()const { return flatsCount; }

    House& addFlat(const Flat& object, int idx);
    House& addFlat(Flat&& object, int idx);

    friend std::ostream& operator<<(std::ostream& out, const House& object);

    ~House() { delete[]flats; }
};

