#include "Flat.h"


Flat::Flat(const Flat& object) :
	persons{ new Person[object.PersonsCount]{} }, PersonsCount{ object.PersonsCount }
{
	for (int i{ 0 }; i < PersonsCount; ++i)
	{
		persons[i] = object.persons[i];
	}
}

Flat::Flat(Flat&& object) :
	persons{ object.persons }, PersonsCount{ object.PersonsCount }
{
	object.persons = nullptr;
	object.PersonsCount = 0;
}


void Flat::_addPersonPlace()
{
	Person* newPersons{ new Person[PersonsCount + 1] };
	for (int i{ 0 }; i < PersonsCount; ++i)
	{
		newPersons[i] = std::move(persons[i]);
	}
	delete[] persons;
	persons = newPersons;
	++PersonsCount;
}

Flat& Flat::addPerson(const Person& object)
{
	_addPersonPlace();
	persons[PersonsCount - 1] = object;
	return *this;
}

Flat& Flat::addPerson(Person&& object)
{
	_addPersonPlace();
	persons[PersonsCount - 1] = std::move(object);
	return *this;
}

Flat& Flat::operator=(const Flat& object)
{
	if (!(this == &object))
	{
		if (PersonsCount != object.PersonsCount)
		{
			delete[]persons;
			persons = new Person[object.PersonsCount];
		}
		PersonsCount = object.PersonsCount;
		for (int i{ 0 }; i < PersonsCount; ++i) { persons[i] = object.persons[i]; }
	}
	return *this;
}

Flat& Flat::operator=(Flat&& object)
{
	if (!(this == &object))
	{
		delete[]persons;
		persons = object.persons;
		PersonsCount = object.PersonsCount;

		object.persons = nullptr;
		object.PersonsCount = 0;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Flat& object)
{	out << "Flat: ";
	if (object.PersonsCount)
	{
		
		for (int i{ 0 }; i < object.PersonsCount; ++i) {out<<object.persons[i]; }
		std::cout << ' ';
	}
	else { out << "[no persons]"; }
	return out;
}