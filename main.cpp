#include "roster.h"
#include "student.h"

int main()
{
    // Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications\tC++\t010762848\tEric Crow" << std::endl << std::endl;
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Eric,Crow,ecrow5@wgu.edu,26,3,6,9,SOFTWARE"
    };

    const int numStudents = 5;
    
    // Create an instance of the Roster class called classRoster.
    Roster classRoster;

    
    // Add each student to classRoster.
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    
    // classRoster.printAll();
    cout << "*Displaying all students* " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // classRoster.printInvalidEmails();
    cout << "*Displaying students with invalid emails*" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    
    // loop through classRosterArray and for each element: classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    cout << "*Displaying average days students spent in course* " << std::endl;
    cout << "Student ID|Average Days Spent in Course" << std::endl;
    for (int i = 0; i <= 4; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;

    // classRoster.printByDegreeProgram(SOFTWARE);
    cout << "*Displaying by degree program: SOFTWARE*" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    // classRoster.remove("A3");
    cout << "*Removing student with ID A3*" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    // classRoster.remove("A3"); should display ID not found;
    cout << "*Removing student with ID A3*" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}