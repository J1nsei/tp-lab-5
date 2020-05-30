#include <string>
#include <vector>
#include <ctime>
#include "Student.h"
#include "Group.h"

Group::Group(std::string title, std::string spec)
{
	this->title = title;
	this->spec = spec;
}

void Group::addstudent(Student student)
{
	students.push_back(student);
	students[students.size() - 1].add_to_group(this);
}

void Group::headman()
{
	srand(time(nullptr));
	int size = students.size();
	head = &students[rand() % size];
}


Student* Group::search_student_id(int id)
{
	for (auto stud : students)
		if (stud.getId() == id)
			return &stud;
	return nullptr;
}

double Group::average_score()
{
	if (students.size() == 0)
		return 0;
	double avg = 0;
	for (auto student : students)
	{
		avg += student.avg_mark();
	}
	return avg / students.size();
}

void Group::kick_from_group(Student student)
{
	if (students.size() == 0)
		return;
	int i = 0;
	for (i = 0; i < students.size(); i++)
		if (students[i].getId() == student.getId())
			break;
	students.erase(students.begin() + i);
}

Student Group::search_student_name(std::string name)
{
	for (auto stud : students)
		if (stud.getname() == name)
			return stud;
}

std::string Group::get_title()
{
	return title;
}
