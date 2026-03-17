#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(const std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();
void sortByLastName(std::vector<Student*>& students);
void sortByFirstName(std::vector<Student*>& students);
void sortByCreditHours(std::vector<Student*>& students);

int main() {
    std::vector<Student*> students;
    loadStudents(students);

    std::string choice = "";

    while (choice != "0") {
        choice = menu();

        if (choice == "0") {
            break;
        } else if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } else if (choice == "4") {
            sortByLastName(students);
            std::cout << "Students sorted by last name." << std::endl;
        } else if (choice == "5") {
            sortByFirstName(students);
            std::cout << "Students sorted by first name." << std::endl;
        } else if (choice == "6") {
            sortByCreditHours(students);
            std::cout << "Students sorted by credit hours." << std::endl;
        } else {
            std::cout << "Invalid choice." << std::endl;
        }

        std::cout << std::endl;
    }

    delStudents(students);
    return 0;
}

void loadStudents(std::vector<Student*>& students) {
    std::ifstream studentFile("students.csv");

    if (!studentFile.is_open()) {
        std::cout << "Unable to open students.csv" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(studentFile, line)) {
        if (!line.empty()) {
            students.push_back(new Student(line));
        }
    }

    studentFile.close();
}

void printStudents(const std::vector<Student*>& students) {
    for (const Student* student : students) {
        student->printStudent();
        std::cout << "____________________________________" << std::endl;
    }
}

void showStudentNames(const std::vector<Student*>& students) {
    for (const Student* student : students) {
        std::cout << student->getLastFirst() << std::endl;
    }
}

void findStudent(const std::vector<Student*>& students) {
    std::string searchText;
    bool foundStudent = false;

    std::cout << "last name of student: ";
    std::getline(std::cin, searchText);

    for (const Student* student : students) {
        if (student->getLastName().find(searchText) != std::string::npos) {
            student->printStudent();
            std::cout << "____________________________________" << std::endl;
            foundStudent = true;
        }
    }

    if (!foundStudent) {
        std::cout << "No students found." << std::endl;
    }
}

void delStudents(std::vector<Student*>& students) {
    for (Student* student : students) {
        delete student;
    }

    students.clear();
}

std::string menu() {
    std::string choice;

    std::cout << "0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << "4) sort by last name" << std::endl;
    std::cout << "5) sort by first name" << std::endl;
    std::cout << "6) sort by credit hours" << std::endl;
    std::cout << std::endl;
    std::cout << "please choose 0-6: ";
    std::getline(std::cin, choice);

    return choice;
}

void sortByLastName(std::vector<Student*>& students) {
    std::sort(students.begin(), students.end(),
        [](const Student* left, const Student* right) {
            if (left->getLastName() == right->getLastName()) {
                return left->getFirstName() < right->getFirstName();
            }

            return left->getLastName() < right->getLastName();
        });
}

void sortByFirstName(std::vector<Student*>& students) {
    std::sort(students.begin(), students.end(),
        [](const Student* left, const Student* right) {
            if (left->getFirstName() == right->getFirstName()) {
                return left->getLastName() < right->getLastName();
            }

            return left->getFirstName() < right->getFirstName();
        });
}

void sortByCreditHours(std::vector<Student*>& students) {
    std::sort(students.begin(), students.end(),
        [](const Student* left, const Student* right) {
            if (left->getCreditHoursCompleted() == right->getCreditHoursCompleted()) {
                if (left->getLastName() == right->getLastName()) {
                    return left->getFirstName() < right->getFirstName();
                }

                return left->getLastName() < right->getLastName();
            }

            return left->getCreditHoursCompleted() > right->getCreditHoursCompleted();
        });
}