#include <algorithm>
#include "student.h"
#include "group.h"
#include <utility>

Student::Student(std::string name, int ID)
{
	this->name = std::move(name);
	this->ID = ID;
}

unsigned int Student::getID()
{
	return ID;
}

std::string Student::getName()
{
	return name;
}

void Student::add(std::string curGroup)
{
	this->group = std::move(curGroup);
}

void Student::setMarks(int mark)
{
	this->marks.push_back(mark);
}

std::vector<int>& Student::getMark()
{
	return marks;
}

unsigned long Student::getAverage()
{
	double sum = 0;
	for (int mark : marks)
	{
		sum += mark;
	}
	return sum / marks.size();
}