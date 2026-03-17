#include <iostream>
#include <sstream>
#include "student.h"

Student::Student() : address(new Address()), birthdate(new Date()), expectedGradDate(new Date()) {
    firstName = "";
    lastName = "";
    creditHoursCompleted = 0;
}

Student::Student(std::string dataString) : address(new Address()), birthdate(new Date()), expectedGradDate(new Date()) {
    firstName = "";
    lastName = "";
    creditHoursCompleted = 0;
    init(dataString);
}

Student::~Student() {
    delete address;
    delete birthdate;
    delete expectedGradDate;
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

    address->init(street, city, state, zip);
    birthdate->init(birthString);
    expectedGradDate->init(gradString);

    creditHoursCompleted = std::stoi(creditsString);
}

void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    std::cout << "DOB: ";
    birthdate->printDate();
    std::cout << "Grad: ";
    expectedGradDate->printDate();
    std::cout << "Credits: " << creditHoursCompleted << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getFirstName() const {
    return firstName;
}

int Student::getCreditHoursCompleted() const {
    return creditHoursCompleted;
}