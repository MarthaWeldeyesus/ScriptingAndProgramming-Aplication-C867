#pragma once
#include <string>
#include "degree.h"
using namespace std;
class Student
{
public:
	const static int numDaysSize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDays[numDaysSize];
	DegreeProgram  degreeType;
public:
	Student(string ID, string first, string last, string email, int setAge, int numDays[], DegreeProgram degreeProgram);
	//Default Constructor
	Student();
	~Student();

	//getter and setter
	string getStudentID();
	void setStudentID(string s);
	string getFirstName();
	void setFirstName(string s);
	string getLastName();
	void setLastName(std::string);
	string getEmailAddress();
	void setEmailAddress(std::string);
	int getAge();
	void setAge(int a);
	int* getNumberOfDays();
	void setNumberOfDays(int numDays[]);
    DegreeProgram  getDegreeType();
	void setDegreeType(DegreeProgram degree);
	
	 void print();

};

