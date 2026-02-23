#include <iostream>
#include <sstream>
#include "date.h"

Date::Date() {
    month = "";
    day = "";
    year = "";
}

Date::Date(std::string dateString) {
    init(dateString);
}

void Date::init(std::string dateString) {
    std::stringstream ss(dateString);
    getline(ss, month, '/');
    getline(ss, day, '/');
    getline(ss, year, '/');
}

void Date::printDate() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}