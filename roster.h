#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkingStudent.h"
#include "softwareStudent.h"

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** students;
public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string sID, string fName, string lName, string Mail, int a, int dc1, int dc2, int dc3, Degree dt);
	void print_All();
	bool remove(string studentID);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printDegreeProgram(Degree d);
	~Roster();
};