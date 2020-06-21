#include "student.h"
#include <string>

using namespace std;

Student::Student(int id, string fio)
{
	this->id = id;
	this->fio = fio;
}

void Student::addGroup(Group* group)
{
	this->group = group;
}

void Student::addMark(int mark)
{
	this->marks.push_back(mark);
}

double Student::middleMark()
{
	if (!(this->marks.empty()))
	{
		double midMark = 0;
		for (int i = 0; i < this->marks.size(); i++)
		{
			midMark += marks[i];
		}
		return midMark / this->marks.size();
	}
	else
		return 0;
}

string Student::getFio()
{
	return fio;
}

int Student::getId()
{
	return id;
}