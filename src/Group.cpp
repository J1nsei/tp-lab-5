#include <iostream>
#include "Group.h"
class Student;
Group::Group(const string& name, const string& spec)
{
	Group::title = name;
	Group::spec = spec;
	Group::head = nullptr;
}

void Group::add(Student* stud)
{
	Group::students.push_back(stud);
	stud->sign_up(this);
}

void Group::expel(Student* stud)
{
	int req_id = stud->get_id();
	stud->group = nullptr;
	for (size_t i = 0; i < students.size(); ++i)
	{
		if (students[i]->get_id() == req_id)
		{
			students.erase(students.begin() + i);
			return;
		}
	}
	throw "No such a student in this group";
}

void Group::assign_head(Student* stud)
{
	Group::head = stud;
}

vector<Student*> Group::find_name(const string& name)
{
	vector<Student*> arr_of_students;
	for (Student* student : students)
	{
		if (student->get_name() == name)
		{
			arr_of_students.push_back(student);
		}
	}
	return arr_of_students;
}

Student* Group::find_id(const int& id)
{
	for (Student* student : students)
	{
		if (student->get_id() == id)
		{
			return student;
		}
	}
	throw "No such id";
}

double Group::average_ball()
{
	double sum = 0;
	for (Student* student : students) 
	{
		sum += student->average_mark();
	}

	return sum / students.size();
}

int Group::size()
{
	return students.size();
}