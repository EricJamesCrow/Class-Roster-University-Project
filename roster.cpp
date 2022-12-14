#include "roster.h"

void Roster::parse(string studentdata)
{
    int rhs = studentdata.find(","); /* find the comma*/
    string sID = studentdata.substr(0, rhs);

    int lhs = rhs + 1; /* move past the previous comma*/
    rhs = studentdata.find(",", lhs);
    string fN = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1; /*keep going*/
    rhs = studentdata.find(",", lhs);
    string lN = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1; /*keep going*/
    rhs = studentdata.find(",", lhs);
    string e = studentdata.substr(lhs, rhs - lhs);

    lhs = rhs + 1; /*keep going*/
    rhs = studentdata.find(",", lhs);
    int a = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1; /*keep going*/
    rhs = studentdata.find(",", lhs);
    int d1 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1; 
    rhs = studentdata.find(",", lhs);
    int d2 = stod(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d3 = stod(studentdata.substr(lhs, rhs - lhs));

    lhs = rhs + 1; /*keep going*/
    rhs = studentdata.find(",", lhs);
    string dp = studentdata.substr(lhs, rhs - lhs);
    DegreeProgram degreeprogram = SECURITY; /* DEFAULT VALUE*/
    if (dp == "SECURITY") degreeprogram = SECURITY;
    else if(dp == "NETWORK") degreeprogram = NETWORK;
    else if(dp == "SOFTWARE") degreeprogram = SOFTWARE;


    add(sID, fN, lN, e, a, d1, d2, d3, degreeprogram);
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int parr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeprogram);
}

void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++) 
    {
        if (classRosterArray[i]->getStudentID() == studentID) 
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }    
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getStudentID(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]->getDays()[0]; cout << '\t';
        cout << classRosterArray[i]->getDays()[1]; cout << '\t';
        cout << classRosterArray[i]->getDays()[2]; cout << '\t';
        cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if(classRosterArray[i]->getStudentID() == studentID) {
            cout << classRosterArray[i]->getStudentID() << ": ";
            cout << (classRosterArray[i]->getDays()[0]
            + classRosterArray[i]->getDays()[1]
            + classRosterArray[i]->getDays()[2])/3.0 << std::endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) 
    {
        string email = (classRosterArray[i]->getEmail());
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) 
        {
            any = true;
            cout << classRosterArray[i]->getStudentID() << ": " << email << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    cout << std::endl;
}


Roster::~Roster()
{
    cout << "---DESTRUCTOR---" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}