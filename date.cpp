#include <iostream>
#include <sstream>
#include <vector>
#include "date.h"

namespace {
std::string monthName(const std::string& monthNumber) {
    static const std::vector<std::string> monthNames = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int monthIndex = std::stoi(monthNumber);
    if (monthIndex >= 1 && monthIndex <= 12) {
        return monthNames[monthIndex];
    }

    return monthNumber;
}

std::string trimLeadingZero(const std::string& numberText) {
    if (numberText.size() > 1 && numberText[0] == '0') {
        return numberText.substr(1);
    }

    return numberText;
}
}

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
    std::cout << monthName(month) << " " << trimLeadingZero(day) << ", " << year << std::endl;
}