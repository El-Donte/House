#pragma once
#include <iostream>
class Person
{
private:
	char* Name;
	char* LastName;
	char* SurName;
public:
	Person() :
		SurName{ nullptr },
		Name{ nullptr },
		LastName{ nullptr }
	{}
	Person(const char* N, const char* L,const char* S);
	Person(const Person& obj);
	Person(Person&& object);

	Person& SetName(const char* N);
	Person& SetLastName(const char* L);
	Person& SetSurName(const char* S);

	char* GetName() { return Name; }
	char* GetLastName() { return LastName; }
	char* GetSurName() { return SurName; }

	friend std::ostream&operator<<(std::ostream& out, const Person& object)
	{
		if (object.SurName and object.LastName and object.Name)
		{
			out << '[' << ' ' << object.LastName
				<< ' ' << object.Name << ' ' << object.SurName << ']' << ' ';
		}
		else { out << "[empty person]"; }
		return out;
	}
	Person& init(const char* S, const char* N, const char* L);
	Person& operator=(Person&& obj);
	Person& operator=(const Person& obj);

	~Person() {
		delete[] Name;
		delete[] LastName;
		delete[] SurName;
	}

};

