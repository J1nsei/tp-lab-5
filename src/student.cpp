#include "student.h"
#include "group.h"
#include <iostream>
#include <string>
#include <vector>

Student::Student(string newName, unsigned int newId)
{
	name = newName;
	id = newId;
}

unsigned int Student::AverageMark() const
{
	int res = 0;
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		res += marks[i];
	}
	res /= marks.size();
	return res;
}

string Student::getName() const
{
	return name;
}

unsigned int Student::getId() const
{
	return id;
}

string Student::getGroup() const
{
	return group->getTitle();
}

void Student::addMark(unsigned int newMark)
{
	marks.push_back(newMark);
}

void Student::setGroup(Group* newGroup)
{
	group = newGroup;
}