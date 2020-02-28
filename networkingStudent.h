#pragma once
#include <string>
#include "student.h"

class networkingStudent : public Student
{
public:
	networkingStudent();
	networkingStudent(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[], Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~networkingStudent();

};

