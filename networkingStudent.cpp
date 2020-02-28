#include <iostream>
#include "networkingStudent.h"
using std::cout;

networkingStudent::networkingStudent() :Student()
{
	dType = NETWORK;
}

networkingStudent::networkingStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree degreeType)
	: Student(studentID, firstName, lastName, Email, Age, daysToComplete)
{
	dType = NETWORK;
}

Degree networkingStudent::getDegreeProgram()
{
	return NETWORK;
}

void networkingStudent::print()
{
	this->Student::print();
	cout << "networking" << "\n";
}

networkingStudent::~networkingStudent()
{
	Student::~Student();
}

