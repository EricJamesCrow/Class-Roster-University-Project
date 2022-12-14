#include "student.h"
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string first) { this->firstName = first; }
void Student::setLastName(string last) { this->lastName = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
    for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
    cout << "Student ID|First Name|Last Name|Email|Age|Days in Course|Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}