#include <iostream>
#include "securityStudent.h"
using std::cout;

securityStudent::securityStudent() :Student()
{
	dType = SECURITY;
}

securityStudent::securityStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree degreeType)
	: Student(studentID, firstName, lastName, Email, Age, daysToComplete)
{
	dType = SECURITY;
}

Degree securityStudent::getDegreeProgram()
{
	return SECURITY;
}

void securityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

securityStudent::~securityStudent()
{
	Student::~Student();
}

