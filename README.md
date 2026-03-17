# Heap-of-Students

```mermaid
classDiagram
class Date {
  -string month
  -string day
  -string year
  +Date()
  +Date(string)
  +init(string)
  +printDate() const
}

class Address {
  -string street
  -string city
  -string state
  -string zip
  +Address()
  +Address(string, string, string, string)
  +init(string, string, string, string)
  +printAddress() const
}

class Student {
  -string firstName
  -string lastName
  -Address* address
  -Date* birthdate
  -Date* expectedGradDate
  -int creditHoursCompleted
  +Student()
  +Student(string)
  +~Student()
  +init(string)
  +printStudent() const
  +getLastFirst() const string
  +getLastName() const string
  +getFirstName() const string
  +getCreditHoursCompleted() const int
}

Student --> Address
Student --> Date
```

## Overview
This program loads students from `students.csv` into a vector, then lets you print names, view all info, search by last name, and sort the records.

- Load students from file
- Print all names (`Last, First`)
- Print full student details
- Search students by last name
- Sort by last name, first name, or credit hours (highest first)
- Delete all students on quit
