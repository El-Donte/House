#include <iostream>
#include "House.h"

House& House::addFlat(const Flat& object, int idx)
{
	flats[idx] = object;
	return *this;
}

House& House::addFlat(Flat&& object, int idx)
{
	flats[idx] = std::move(object);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const House& object)
{
    if (object.flatsCount and object.flats)
    {
        out << "Home:"<< ' ' << object.flatsCount << " flats:\n";
        if (object.flats)
        {
            for (int i{ 0 }; i < object.flatsCount; ++i) { out << object.flats[i] << '\n'; }
        }
        else { out << "[empty flats]"; }
    }
    else { out << "[empty home]"; }
    return out;
}


