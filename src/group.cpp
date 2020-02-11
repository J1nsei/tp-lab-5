
#include "Student.h"
#include "group.h"
#include <random>

Group::Group(string title, string spec)
{
	this->title = title;
	this->spec = spec;
}

void Group::add_student(Student* new_student)
{
	students.push_back(new_student);
}

void Group::choose_head()
{
	int i = rand() % students.size();
	head = students[i];
}

Student * Group::find_student_fio(string fio)
{
	for (auto student : students)
	{
		if (student->getFio() == fio)
			return student;
		else
			return 0;
	}
}

Student * Group::find_student_id(int id)
{
	for (auto student : students)
	{
		if (student->getId() == id)
			return student;
		else
			return 0;
	}
}

float Group::average_mark()
{
	float sum = 0;
	for (auto student : students)
	{
		sum += student->average_mark();
	}
	return sum / students.size();
}

void Group::delete_student(Student* student)
{
	int i = 0, j = -1;
	for (auto stud : students)
	{
		i++;
		if (stud == student)
			j = i;
	}
	students.erase(students.begin() + j - 1);
}

string Group::getTitle()
{
	return title;
}

string Group::getSpec()
{
	return spec;
}

vector<Student*> Group::getStudents()
{
	return students;
}

Student* Group::getHead()
{
	return head;
}