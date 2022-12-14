#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
    const static int daysArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daysArraySize];
    DegreeProgram degreeProgram;
public:
    Student();/*parameterless constructor - sets to default*/
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
    ~Student();/*destructor*/

    /*getters aka accessors*/
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    /* setters aka mutators */
    void setStudentID(string ID);
    void setFirstName(string First);
    void setLastName(string Last);
    void setEmail(string Email);
    void setAge(int Age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram bt);

    static void printHeader();/*displays a header for the data to follow*/

    void print();
};