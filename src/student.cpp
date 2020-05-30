#include "student.h"

Student::Student(int id, string fio)
{
	this->fio = fio;
	this->id = id;
	group = NULL;
}

Student::~Student()
{
}


 void Student::addToGroup(Group* group)
{
	this->group = group;
	//group->addStudent(this);
}

void Student::addMark(int mark)
{
	marks.push_back(mark);
}

int Student::meanMark()
{
	int n = marks.size();
	int mean = 0;
	for (int i = 0; i < n; i++)
	{
		mean += marks.at(i);
	}
	mean = mean / 2;
	return mean;
}

string Student::getFIO()
{
	return fio;
}

int Student::getID()
{
	return id;
}

Group* Student::getGroup()
{
	return group;
}

void Student::setFIO(string fio)
{
	this->fio = fio;
}

void Student::setID(int id)
{
	this->id = id;
}

bool Student::is_head()
{
	if (getGroup()->getHead() == this)
	{
		return true;
	}
	return false;
}

void Student::printStudentInf()
{
	cout << fio << " ID: " << id << " mean mark: " << meanMark() << endl;
}
