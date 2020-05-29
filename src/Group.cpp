#include "Group.h"
#include "Deanery.h"
#include "Student.h"

Group::Group(string title)
{
	this->title = title;

}

void Group::addStudent(Student *student)
{
	this->students.push_back(student);
}

Student* Group::headman()
{
	if (students.size() > 0)
	{
		if (students.size() > 1)
		{
			int hman = rand() % students.size();
			head = students[hman];
			return head;
		}
		else head = students[0];
		return head;
	}
	else return nullptr;
}

Student* Group::searchStudent(int ID)
{
	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i]->getID() == ID)
			return this->students[i];
	}
}

double Group::averageMarkGroup()
{
	double sum = 0;

	for (int i = 0; i < students.size(); i++)
	{
		sum += students[i]->getAvarageMarks();
	}
	return sum / students.size();
}

void Group::deleteStudent(int ID)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->ID == ID)
		{
			if (students[i] == head)
			{
				students.erase(students.begin() + i);
				headman();
			}
			else
			{
				students.erase(students.begin() + i);
			}

		}
	}
}

int Group::studSize()
{
	return students.size();
}