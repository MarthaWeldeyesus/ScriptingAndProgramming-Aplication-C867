#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;

int main() {
	cout << "C867/-Scripting & Programming: Applications " << endl;
	cout << "Language: C++ " << endl;
	cout << "Student ID: 001475537 " << endl;
	cout << "Name: Martha Weldeyesus" << endl << endl;

    const int studentCount = 5; 

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Martha,Weldeyesus,mweldeye@wgu.edu,21,30,40,35,SOFTWARE"
    };
    
    Roster* classRoster = new Roster(studentCount); 

    for (int i = 0; i < studentCount; i++)
    { 
        classRoster->parsedSudentData(studentData[i]);

    }

    cout << "Done" << endl;
    
    classRoster->printAll();
    classRoster->printInvalidEmails();

    std::cout << "Displaying Students Average: " << std::endl << std::endl;
    for (int i = 0; i < classRoster->headCount; i++)
    {
        classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID());
    }
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    return 0;

}