#include "group.h"

Group::Group(string title)
{
	this->title = title;
	spec = "";
	head = NULL;
}

Group::~Group()
{
}

 void Group::addStudent(Student* student)
{
	student->addToGroup(this);
	students.push_back(student);
}

void Group::setTitle(string title)
{
	this->title = title;
}

void Group::setHead(Student* student)
{
	head = student;
}

void Group::setRandHead()
{
	int rand_num = rand() % students.size();
	setHead(students.at(rand_num));
}

void Group::setSpec(string spec)
{
	this->spec = spec;
}

void Group::setRandMarks()
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		students.at(i)->addMark((rand() % 11) * students.at(i)->getID() % 11);
	}
}

int Group::getMeanMark()
{
	int mean = 0;
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		mean += students.at(i)->meanMark();
	}
	mean = mean / n;
	return mean;
}

string Group::getTitle()
{
	return title;
}

string Group::getSpec()
{
	return spec;
}

Student* Group::getHead()
{
	return head;
}

void Group::printStudents()
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		cout << students.at(i)->getFIO() << " id: " << students.at(i)->getID();
		if (students.at(i)->is_head())
		{
			cout << " head";
		}
		cout << endl;
	}
}

void Group::saveStudents(ofstream& out)
{
	int n = students.size();
	for (int i = 0; i < n-1; i++)
	{
		out << students.at(i)->getFIO() << endl;
		out << students.at(i)->getID() << endl;
		out << "%" << endl;
	}
	out << students.at(n-1)->getFIO() << endl;
	out << students.at(n-1)->getID() << endl;
	out << "!" << endl;
}

void Group::printStatistic()
{
	int n = students.size();
	cout << title << " mean mark: " << getMeanMark() << endl;
	for (int i = 0; i < n; i++)
	{
	    students.at(i)->printStudentInf();
	}
}

Student* Group::findStudent(string fio)
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students.at(i)->getFIO() == fio)
		{
			return students.at(i);
		}
	}
	return nullptr;
}

Student* Group::findStudent(int id)
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students.at(i)->getID() == id)
		{
			return students.at(i);
		}
	}
	return nullptr;
}

Student* Group::findLooser()
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students.at(i)->meanMark() < 4)
		{
			return students.at(i);
		}
	}
	return nullptr;
}

void Group::studentExpell(Student* s)
{
	int n = students.size();
	for (int i = 0; i < n; i++)
	{
		if (students.at(i) == s)
		{
			students.erase(students.begin() + i);
			return;
		}
	}
}
