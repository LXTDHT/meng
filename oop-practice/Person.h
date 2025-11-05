#pragma once

#include <string>
#include <vector>

typedef std::string string;
// typedef std::vector<int> vector_int;

class Person {
public:
    string name;
    float age;

    Person(const string& n); // constructor
    virtual ~Person(); // destructor - Always make virtual on a base class

    void haveBirthday(); // This method cannot be overridden

    virtual float estimateHeight() const; // This method can be overridden but may not mutate state
};

class Student : public Person {
public:
    Student(const string& n);

    std::vector<int> grades;

    virtual float estimateHeight() const;
};