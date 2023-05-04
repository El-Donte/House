#include "Person.h"

Person::Person(const char* N, const char* L, const char* S) : 
	SurName{ new char[strlen(S) + 1] },
	Name{ new char[strlen(N) + 1] }, 
	LastName{ new char[strlen(L) + 1] }
{
	strcpy_s(Name, strlen(N) + 1, N);
	strcpy_s(LastName, strlen(L) + 1, L);
	strcpy_s(SurName, strlen(S) + 1, S);
}

Person::Person(const Person& obj):
	Name{new char[strlen(obj.Name) + 1]},
	LastName{new char[strlen(obj.LastName) + 1]},
	SurName{new char[strlen(obj.SurName) + 1]}
{
	strcpy_s(Name, strlen(obj.Name) + 1, obj.Name);
	strcpy_s(LastName, strlen(obj.LastName) + 1, obj.LastName);
	strcpy_s(SurName, strlen(obj.SurName) + 1, obj.SurName);
}

Person::Person(Person&& object) :
	SurName{ object.SurName }, Name{ object.Name }, LastName{ object.LastName }
{
	object.SurName = nullptr;
	object.Name = nullptr;
	object.LastName = nullptr;
}

Person& Person::SetName(const char* N) {
	if (N) {
		if (Name) delete[]Name;
		Name = new char[strlen(N) + 1];
		strcpy_s(Name, strlen(N) + 1, N);
		return *this;
	}
}
Person& Person::SetLastName(const char* L) {
	if (L) {
		if (LastName) delete[]LastName;
		LastName = new char[strlen(L) + 1];
		strcpy_s(LastName, strlen(L) + 1, L);
		return *this;
	}
}
Person& Person::SetSurName(const char* S) {
	if (S) {
		if (SurName) delete[]SurName;
		SurName = new char[strlen(S) + 1];
		strcpy_s(SurName, strlen(S) + 1, S);
		return *this;
	}
}

Person& Person::init(const char* S,const char* N,const char* L)
{
	SetSurName(S); SetName(N); SetLastName(L);
	return *this;
}

Person& Person::operator=(Person&& obj) {
	if (this == &obj) { return *this; }
	delete[] Name;
	delete[] SurName;
	delete[] LastName;

	SurName = obj.SurName;
	Name = obj.Name;
	LastName = obj.LastName;

	obj.SurName = nullptr;
	obj.Name = nullptr;
	obj.LastName = nullptr;

	return *this;
}

Person& Person::operator=(const Person& obj) {
	if (this == &obj) { return *this; }
	delete[] Name;
	delete[] SurName;
	delete[] LastName;

	SurName = new char[strlen(obj.SurName)+1];
	Name = new char[strlen(obj.Name)+1];
	LastName = new char[strlen(obj.LastName)+1];

	strcpy_s(Name, strlen(obj.Name) + 1, obj.Name);
	strcpy_s(LastName, strlen(obj.LastName) + 1, obj.LastName);
	strcpy_s(SurName, strlen(obj.SurName) + 1, obj.SurName);

	return *this;
}


