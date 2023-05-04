#include <iostream>
#include "House.h"
#include "Person.h"
#include "Flat.h"


int main(){
    Person* kravchuki{ new Person[3] };
    kravchuki[0].init("Kravchuk", "Mykola", "Mykolayovich");

    Person* hapchuki{ new Person[3] };
    hapchuki[0].init("Hapchuk", "Ostap", "Petrovich");

    Person person_1{"tsthsdhk","Stshan","srthvich"};
    Person person_2{"thsrova","htsna","Stssvna"};

    Flat flat_1;
    Flat flat_2;
    Flat flat_3;

    for (int i{ 0 }; i < 1; ++i) { flat_1.addPerson(std::move(kravchuki[i])); }
    flat_2.addPerson(person_1);
    flat_3.addPerson(Person{"Pjdty", "htrhht", "Mhtrth"}).addPerson(Person{"thrsht", "htsr", "Stetrdha"});
    Flat flat_5;
    for (int i{ 0 }; i < 1; ++i) { flat_5.addPerson(std::move(hapchuki[i])); }

    std::cout << flat_1 << '\n' << flat_2 << '\n' << flat_3 << '\n';

    House home_1;
    House home_2{8};
    std::cout << home_1 << '\n' << home_2 << '\n';

    home_1.addFlat(flat_1, 0).addFlat(flat_2, 1).addFlat(flat_3, 2);
    std::cout << home_1 << '\n';
    home_2.addFlat(std::move(flat_5), 0).addFlat(std::move(flat_3), 2);
    std::cout << home_1 << '\n' << home_2 << '\n';

    delete[]kravchuki;
    delete[]hapchuki;

    return 0;

}