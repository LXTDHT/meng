// #include <memory>
#include <iostream>
#include "Person.h"

int main(const int argc, const char* argv[]) {
    Person meek("Meek J"); // stack
    Person& meekRef(meek); // stack
    Person* kim(new Student("Kim P")); // heap
    std::shared_ptr<Person> chris(std::make_shared<Student>("Chris H"));

    meek.haveBirthday();
    meekRef.haveBirthday(); // Meek is now 2
    kim->haveBirthday();
    chris->haveBirthday();

    std::cout << meek.name << std::endl;

    // Deallocating memory
    delete kim;
    kim = nullptr;

    // return 0;
}