#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
	const static int durationArraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string Email;
	int Age;
	int daysToComplete[durationArraySize];
	Degree dType;

public:
	Student();

	Student(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[]);

	//Getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	
	virtual Degree getDegreeProgram() = 0;

	//Setters
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string Email);
	void setAge(int Age);
	void setDaysToComplete(int daysTocomplete[]);

	virtual void print() = 0;

	//Destuctor
	~Student();
};

