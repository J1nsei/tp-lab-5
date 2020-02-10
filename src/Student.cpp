#include "Group.h"
#include "Student.h"

Student::Student(int ID, string FIO)
{
	this->FIO = FIO;
	this->ID = ID;
}

int Student::getID()
{
	return ID;
}

string Student::getFIO()
{
	return FIO;
}

void Student::addToGroup(string group)
{
	this->group = group;
}

void Student::setMarks(int mark)
{
	this->marks.push_back(mark);
}

vector<int>& Student::getMarks()
{
	return marks;
}

int Student::getAvarageMarks()
{
	int sum = 0;

	for (int i = 0; i < marks.size(); i++) 
	{
		sum += marks[i];
	}
	return sum / marks.size();
}