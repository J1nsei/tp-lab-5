#include "student.h"
#include "group.h"
#include "decan.h"
#include <utility>

Group::Group(std::string groupName)
{
	this->groupName = std::move(groupName);
}

void Group::addStudent(Student* student)
{
	this->student.push_back(student);
}

Student* Group::setHead()
{
	if (student.empty()) return nullptr;
	else
	{
		if (student.size() > 1)
		{
			int curHead = rand() % student.size();
			head = student[curHead];
			return head;
		}
		else head = student[0];
		return head;
	}	
}

Student* Group::findStudent(int ID)
{
	for (auto& student : this->student)
	{
		if (student->getID == ID)
			return student;
	}
	return nullptr;
}

double Group::getAverage()
{
	double marks = 0;
	for (auto& student : student)
	{
		marks += student->getAverage();

	}
	int sum = marks / student.size();
	return sum;
}

void Group::kickStudent(int ID)
{
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i]->ID == ID)
		{
			if (student[i] == head)
			{
				student.erase(student.begin() + i);
				setHead();
			}
			else
			{
				student.erase(student.begin() + i);
			}
		}
	}
}

int Group::getSize()
{
	return student.size();
}
