#include <iostream>
#include <sstream>
#include "student.h"

Student::Student() {
    firstName = "";
    lastName = "";
    creditHoursCompleted = 0;
}

Student::Student(std::string dataString) {
    init(dataString);
}

void Student::init(std::string dataString) {
    std::stringstream ss(dataString);
    std::string street, city, state, zip;
    std::string birthString, gradString;
    std::string creditsString;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, birthString, ',');
    getline(ss, gradString, ',');
    getline(ss, creditsString, ',');

    address.init(street, city, state, zip);
    birthdate.init(birthString);
    expectedGradDate.init(gradString);

    creditHoursCompleted = std::stoi(creditsString);
}

void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address.printAddress();
    std::cout << "DOB: ";
    birthdate.printDate();
    std::cout << "Grad: ";
    expectedGradDate.printDate();
    std::cout << "Credits: " << creditHoursCompleted << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}