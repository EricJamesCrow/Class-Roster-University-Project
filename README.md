# Class Roster Management System

This is a C++ application that manages a roster of students for a university project. 
![](https://raw.githubusercontent.com/EricJamesCrow/Class-Roster-School-Project/main/gifs/classRosterDemo.gif?token=GHSAT0AAAAAAB4LRH7KNTJAXPEOSD24GME4ZDAFHCQ)

## Overview

The application is designed to maintain a current roster of students within a given course. Student data for the program includes student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program. 

The student data is read from a predefined list, parsed, and stored in a roster. The application includes features for adding and removing students from the roster, printing student details, and computing and printing average days to complete a course. It also verifies student email addresses and prints all invalid ones.

## Project Structure

The project consists of six source code files:

- degree.h: Contains the definition of an enumerated data type `DegreeProgram` for the degree programs.
- student.h and student.cpp: Define the `Student` class, which includes student-specific data and related functions.
- roster.h and roster.cpp: Define the `Roster` class, which contains an array of `Student` objects and functions to manipulate the student roster.
- main.cpp: Contains the `main` function, which demonstrates the required functionality of the application.

## Functionality

The application demonstrates the following functionality:

1. Print out to the screen the course title, the programming language used, student ID, and student name.
2. Creation of an instance of the Roster class called `classRoster`.
3. Adding each student to `classRoster`.
4. Printing all student data, invalid email addresses, and average number of days for each student to complete the course.
5. Printing student data for a specified degree program.
6. Removing students from the roster by student ID.
7. Implementing the destructor to release the memory that was allocated dynamically in `Roster`.

## Author

Eric Crow
