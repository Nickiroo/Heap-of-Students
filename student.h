#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* birthdate;
    Date* expectedGradDate;
    int creditHoursCompleted;

public:
    Student();
    Student(std::string dataString);
    ~Student();

    Student(const Student&) = delete;
    Student& operator=(const Student&) = delete;

    void init(std::string dataString);
    void printStudent() const;
    std::string getLastFirst() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    int getCreditHoursCompleted() const;
};

#endif