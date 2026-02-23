#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    std::string month;
    std::string day;
    std::string year;

public:
    Date();
    Date(std::string dateString);

    void init(std::string dateString);
    void printDate() const;
};

#endif