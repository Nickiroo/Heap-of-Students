#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName;
    std::string lastName;
    Address address;
    Date birthdate;
    Date expectedGradDate;
    int creditHoursCompleted;

public:
    Student();
    Student(std::string dataString);

    void init(std::string dataString);
    void printStudent() const;
    std::string getLastFirst() const;
};

#endif