#pragma once
#include "student.h"


class Roster
{
public: 
    int studentPosition; 
    int headCount; 
    Student** students; 

    Roster();
    Roster(int headCount); 
    ~Roster();

    void parsedSudentData(string rawData);
    DegreeProgram convert(string str); 
    void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void printAll(); 
    void remove(string studentID); 
    void printAverageDaysInCourse(string studentID); 
    void printInvalidEmails(); 
    void printByDegreeProgram(DegreeProgram degreeProgram); 

};




