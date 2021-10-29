#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

Roster::Roster()
{
       headCount = 0;
       studentPosition = -1;
       students = nullptr; 
}
Roster::Roster(int headCount) 
{
    this->headCount = headCount;
    this->studentPosition = -1;
    this->students = new Student * [headCount]; 
}

void Roster::parsedSudentData(string rawData)
{ 
    std::vector<string> dataPoints; 
    std::stringstream inputSStream(rawData); 

    while (inputSStream.good())
    { 
        string data;
        getline(inputSStream, data, ',');
        dataPoints.push_back(data);
    }
    add(dataPoints.at(0), 
        dataPoints.at(1),
        dataPoints.at(2), 
        dataPoints.at(3), 
        stoi(dataPoints.at(4)), 
        stoi(dataPoints.at(5)), 
        stoi(dataPoints.at(6)), 
        stoi(dataPoints.at(7)), 
        convert(dataPoints.at(8)) 
    );
}
DegreeProgram Roster::convert(string str)
{ 
    if (str == "SECURITY") return SECURITY;
    else if (str == "NETWORK") return NETWORK;
    else if (str == "SOFTWARE") return SOFTWARE;

}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    if (studentPosition < headCount)
    { 
        studentPosition++;
        students[studentPosition] = new Student();
        students[studentPosition]->setStudentID(studentID);
        students[studentPosition]->setFirstName(firstName);
        students[studentPosition]->setLastName(lastName);
        students[studentPosition]->setEmailAddress(emailAddress);
        students[studentPosition]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        students[studentPosition]->setNumberOfDays(days);
        students[studentPosition]->setDegreeType(degreeProgram);
    }
    else 
    {
        std::cerr << std::endl << "ERROR! YOUR ROSTER HAS EXCEEDED YOUR HEAD COUNT OF STUDENTS!" << std::endl << std::endl;
    }
}
void Roster::printAll() 
{
    std::cout << "Displaying all students:" << std::endl;
    for (int i = 0; i <= this->studentPosition; i++)
    {

        (this->students)[i]->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Roster::remove(string studentID)
{ 

    bool found = false; 

    for (int i = 0; i <= studentPosition; i++)
    {
        if (this->students[i]->getStudentID() == studentID) 
        {
            found = true; 
            delete this->students[i];
            for (int j = i; j < studentPosition; j++)
            {
                this->students[j] = this->students[j + 1];
            }        
            studentPosition--;
            std::cout << "Successfully Removed student: " << studentID << std::endl << std::endl;
            return;
        }
    }
    std::cout << "Student " << studentID << " not found.";

}
void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false; 

    for (int i = 0; i <= studentPosition; i++)
    {
        if (this->students[i]->getStudentID() == studentID)
        {
            found = true;
            int* days = this->students[i]->getNumberOfDays(); 
            double averageDays = (int)(static_cast<double>(days[0] + days[1] + days[2]) / 3.0); 
            std::cout << "Student ID: " << studentID << ", averages: "
                << averageDays << " days in a course." << std:: endl;
            return;
        }
    }
 
}
void Roster::printInvalidEmails()
{
    std::cout << "Displaying Invalid Email:" << std::endl << std::endl;
    bool found = false; 

    for (int i = 0; i <= studentPosition; i++)
    {
        string email = this->students[i]->getEmailAddress();
      
        if (email.find('.') == string::npos) {
            cout << students[i]->getEmailAddress() << " missing a period." << endl;
        }
        else if (email.find('@') == string::npos) {
            cout << students[i]->getEmailAddress() << " missing an @ symbol." << endl;
        }
        else if (!(email.find(' ') == string::npos)) {
            cout << students[i]->getEmailAddress() << " no spaces allowed." << endl;
        }
    }
    std::cout << std::endl;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    std::cout << endl;
    std::cout << "Displaying Students in the " << degreeProgramType[degreeProgram] << " degree program: " << std::endl << std::endl;
    for (int i = 0; i <= studentPosition; i++)
    {
        if (this->students[i]->getDegreeType() == degreeProgram)
        {
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
