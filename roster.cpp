#include "roster.h"
using namespace std;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
	return students[index];
}

void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degreeType = SECURITY;
		
		int rhs = row.find(",");
		string dID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string mail = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int a = stoi(row.substr(lhs, rhs - lhs));


		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dc1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dc2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dc3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string major = row.substr(lhs, rhs - lhs);
		if (major == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		if (major == "NETWORK") {
			degreeType = NETWORK;
		}
		add(dID, fName, lName, mail, a, dc1, dc2, dc3, degreeType);
	}
}

void Roster::add(string dID, string fName, string lName, string mail, int a, int dc1, int dc2, int dc3, Degree dt)
{
	int classDuration[Student::durationArraySize];
	classDuration[0] = dc1;
	classDuration[1] = dc2;
	classDuration[2] = dc3;
	if (dt == SECURITY) students[lastIndex] = new securityStudent(dID, fName, lName, mail, a, classDuration, dt);
	else if (dt == NETWORK) students[lastIndex] = new networkingStudent(dID, fName, lName, mail, a, classDuration, dt);
	else students[lastIndex] = new softwareStudent(dID, fName, lName, mail, a, classDuration, dt);
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getID() == ID)
		{
			found = true;
			delete this->students[i];
			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getID() == studentID)
		{
			found = true;
			int* d = students[i]->getDaysToComplete();
			cout << "AVERAGE DAYS TILL COMPLETEION " << studentID << " IS " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "COMPLETION TIME NOT FOUND.\n";
}

void Roster::printInvalidEmails()
{
	cout << "DISPLAYING INVALID EMAIL ENTRY:\n";
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		any = false;
		int* d = students[i]->getDaysToComplete();
		for (int j = 0; j <= Student::durationArraySize; j++)
		{
			if (d[j] <= 0)
			{
				any = true;
				cout << "BOOK ID " << students[i]->getEmail() << ": ";
				cout << d[j] << " ";
			}
			if (any) cout << "\n";
		}
		if (!any) cout << "NONE";
	}
}

void Roster::printDegreeProgram(Degree d)
{
	cout << "PRINT STUDENTS BY DEGREE PROGRAM " << degreeTypeString[d] << "\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getDegreeProgram() == d) this->students[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->students[i];
	}
	delete students;
}

int main()
{
	int classRoster = 5;
	string classRosterArray[5] =
	{
		"A1, John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2, Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3, Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4, Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5, Andrew,Presas,fakeoemail@email.com,28,35,45,50,SOFTWARE"
	};

	Roster* ros = new Roster(classRoster);
	cout << "PARSING DATA AND ADDING STUDENTS: \t";
	for (int i = 0; i < classRoster; i++)
	{
		ros->parseThenAdd(classRosterArray[i]);
	}
	cout << "DONE.\n";
	cout << "DISPLAYING ALL STUDENTS:\n";
	ros->print_All();

	cout << "REMOVING A4:\n";
	if (ros->remove("A4")) {
		ros->print_All();
		classRoster--;
	}
	else cout << "STUDENT NOT FOUND.\n";

	cout << "REMOVING A4:\n";
	if (ros->remove("A4")) ros->print_All();
	else cout << "STUDENT NOT FOUND.\n";

	cout << "PRINTING AVERAGE DAYS TO COMPLETE DEGREE PROGRAM:\n";
	for (int i = 0; i < classRoster; i++)
	{
		ros->printDaysInCourse(ros->getStudentAt(i)->getID());
	}
	ros->printInvalidEmails();

	for (int i = 0; i < 2; i++) ros->printDegreeProgram((Degree)i);

	system("pause");
	return 0;
}