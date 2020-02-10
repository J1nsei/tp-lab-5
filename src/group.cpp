#include "student.h"
#include "group.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

Group::Group(string title, string specName)
{
	groupName = title;
	spec = specName;
}

void Group::addStudent(Student* newStudent)
{
	students.push_back(newStudent);
	newStudent->setGroup(this);
}

void Group::expelStudent(Student* newStudent)
{
	for (unsigned int i = 0; i < students.size(); i++)
	{
		if (newStudent == students[i])
		{
			students.erase(students.begin() + i);
		}
	}
}

string Group::getTitle() const
{
	return groupName;
}

string Group::getSpec() const
{
	return spec;
}

string Group::getHeadName() const
{
	return head->getName();
}

vector<Student*> Group::getStudents() const
{
	return students;
}

void Group::chooseHead()
{
	int num = rand() % (students.size());
	head = students[num];
}

unsigned int Group::AverageMarkofGroup() const
{
	int res = 0;
	for (unsigned int i = 0; i < students.size(); i++)
	{
		res += students[i]->AverageMark();
	}
	res /= students.size();
	cout << " Average mark of " << getTitle() << " is " << res << endl;
	return res;
}

Student * Group::findbyName(string name) const
{
	for (unsigned int i = 0; i < students.size(); i++)
	{
		if (students[i]->getName() == name)
			return students[i];
	}
	cout << "This student is not in this group" << endl;
}

Student * Group::findbyId(int id) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i]->getId() == id)
			return students[i];
	}
	cout << "This student is not in this group" << endl;
}