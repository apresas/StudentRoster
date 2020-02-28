#pragma once
#include <string>
#include "student.h"

class softwareStudent : public Student
{
public:
	softwareStudent();
	softwareStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree dType);

	Degree getDegreeProgram();
	void print();

	~softwareStudent();

};

