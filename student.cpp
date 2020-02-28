#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentID = " ";
	this->firstName = " ";
	this->lastName = " ";
	this->Email = " ";
	this->Age = 0;
	for (int i = 0; i < durationArraySize; i++) this->daysToComplete[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string Email, int Age, int daysToComplete[])
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->Email = Email;
	this->Age = Age;
	for (int i = 0; i < durationArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
}

//Getters
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return Email;
}

int Student::getAge()
{
	return Age;
}

int* Student::getDaysToComplete()
{
	return daysToComplete;
}

//Setters
void Student::setID(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string Email)
{
	this->Email = Email;
}

void Student::setAge(int Age)
{
	this->Age = Age;
}

void Student::setDaysToComplete(int daysTocomplete[])
{
	for (int i = 0; i < durationArraySize; i++)
		this->daysToComplete[i] = daysToComplete[i];
}

void Student::print()
{
	cout << left << setw(2) << studentID;
	cout << left << setw(20) << firstName;
	cout << left << setw(20) << lastName;
	cout << left << setw(30) << Email;
	cout << left << setw(3) << Age;
	cout << left << setw(3) << daysToComplete[0];
	cout << left << setw(3) << daysToComplete[1];
	cout << left << setw(3) << daysToComplete[2];
	cout << left << setw(3) << daysToComplete[2];
}

Student::~Student()
{

}