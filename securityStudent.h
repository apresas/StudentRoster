#pragma once
#include <string>
#include "student.h"

class securityStudent : public Student
{
public:
	securityStudent();
	securityStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~securityStudent();

};


