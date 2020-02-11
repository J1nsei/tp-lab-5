#include "student.h"
#include "group.h"
#include <iostream>
#include <string>
#include <vector>

Student::Student(std::string name, unsigned int id)
{
	this->name = name;
	this->id = id;
}

float Student::get_average() const
{
	int sum = 0;
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
	}
	return sum / marks.size();
}

std::string Student::get_name() const
{
	return name;
}

unsigned int Student::get_id() const
{
	return id;
}

std::string Student::get_group() const
{
	return group->get_title();
}

void Student::add_mark(unsigned int mark)
{
	marks.push_back(mark);
}

void Student::set_group(Group* group)
{
	this->group = group;
}