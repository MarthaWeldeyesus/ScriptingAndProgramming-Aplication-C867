#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;


Student::Student(string ID, string first, string last, string email, int setAge, int numDays[], DegreeProgram degreeProgram)
{
	studentID = ID;
	firstName = first;
	lastName = last;
	emailAddress = email;
	age = setAge;

	for (int i = 0; i < numDaysSize; i++)
	{
		numberOfDays[i] = numDays[i];
	}
	degreeType = degreeProgram;
}
// Default constructor

Student::Student() {}
//Destructor
Student::~Student() {}

string Student::getStudentID()
{
	return studentID;
}

void Student::setStudentID(string s)
{
	studentID = s;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string s)
{
	firstName = s;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string s)
{
	lastName = s;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

void Student::setEmailAddress(string s)
{
	emailAddress = s;
}

int Student::getAge()
{
	return age;
}

void Student::setAge(int s)
{
	age = s;
}

int * Student::getNumberOfDays()
{
	return numberOfDays;
}

void Student::setNumberOfDays(int numDays[])
{
	for (int i = 0; i < numDaysSize; i++)
	{
		numberOfDays[i] = numDays[i];
	}
}

DegreeProgram Student::getDegreeType()
{
	return degreeType;
}

void Student::setDegreeType(DegreeProgram s)
{
	degreeType = s;
}
void Student::print() {
	cout << studentID << "\t"
		<< "First Name: " << firstName << "\t"
		<< "Last Name: " << lastName << "\t"
		<< "Age: " << age << "\t"
		<< "daysInCourse: {" << numberOfDays[0] << ", "
		<< numberOfDays[1] << ", "
		<< numberOfDays[2] << "} "
		<< "Degree Program: " << degreeProgramType[getDegreeType()];
}





