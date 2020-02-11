#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "student.h"
#include "group.h"

Group::Group(std::string title, std::string spec)
{
	this->title = title;
	this->spec = spec;
}

void Group::add_student(Student* student)
{
	students.push_back(student);
	student->set_group(this);
}

Student* Group::find(const std::string& name) const
{
	for (unsigned int i = 0; i < students.size(); i++)
	{
		if (students[i]->get_name() == name)
			return students[i];
	}
	return nullptr;
}

Student* Group::find(unsigned int id) const
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i]->get_id() == id)
			return students[i];
	}
	return nullptr;
}

void Group::allocation(Student* student)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (student == students[i])
		{
			students.erase(students.begin() + i);
		}
	}
}

std::string Group::get_title() const
{
	return title;
}

std::string Group::get_spec() const
{
	return spec;
}

std::string Group::get_head() const
{
	return head->get_name();
}

std::vector<Student*> Group::get_students() const
{
	return students;
}

void Group::elect_head()
{
	head = students[rand() % (students.size())];
}

float Group::get_average_group() const
{
	int sum = 0;
	for (unsigned int i = 0; i < students.size(); i++)
	{
		sum += students[i]->get_average();
	}
	return sum / students.size();
}

