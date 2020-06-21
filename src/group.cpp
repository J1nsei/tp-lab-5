#include "group.h"
#include <string>
#include <vector>

using namespace std;

Group::Group(string title, string spec)
{
	this->title = title;
	this->spec = spec;

}

void Group::addStudent(Student* student)
{
	student->addGroup(this);
	this->students.push_back(student);
}

void Group::headChoice(Student* head)
{
	this->head = head;
}

Student* Group::searchStudentFIO(string fio)
{
	for (int i = 0; i < this->students.size();++i)
	{
		if (students[i]->getFio() == fio)
			return students[i];
	}
	return nullptr;
}

Student* Group::searchStudentID(int id)
{
	for (int i = 0; i < this->students.size(); i++)
	{
		if (students[i]->getId() == id)
			return students[i];
	}
	return nullptr;
}

double Group::middleGroupMark(Group* group)
{
	double mid = 0;
	for (auto student : students)
	{
		mid += student->middleMark();
	}
	return mid / students.size();
}

void Group::byeStudent(Student *student)
{
	int i = 0;
	for (auto stud : students)
	{
		if (stud->getId() == student->getId())
		{
			students.erase(students.begin() + i);
			break;
		}
		++i;
	}
}

string Group::info()
{
	string str = this->title + " " + this->spec;
	return str;
}