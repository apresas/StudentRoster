#include <iostream>
#include "softwareStudent.h"
using std::cout;

softwareStudent::softwareStudent() :Student()
{
	dType = SOFTWARE;
}

softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree degreeType)
	: Student(studentID, firstName, lastName, Email, Age, daysToComplete)
{
	dType = SOFTWARE;
}

Degree softwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void softwareStudent::print()
{
	this->Student::print();
	cout << "software" << "\n";
}

softwareStudent::~softwareStudent()
{
	Student::~Student();
}

