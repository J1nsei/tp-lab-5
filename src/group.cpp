#define _CRT_SECURE_NO_WARNINGS
#include "group.h"
#include "dean.h"

Group::Group(string init_name)
{
	name = init_name;	
	spec = init_name.assign(init_name, init_name.find("-") + 1, init_name.size() - 1);
}

void Group::addStudent(Student* new_student) {
	students.push_back(new_student);
}

string Group::getName() {
	return name;
}

void Group::setMarks() {
	for (auto st : students)
		st->setMarks();
}

void Group::appointHead() {
	srand(time(NULL));
	unsigned int head_id = rand() % students.size();
	head = students[head_id];
}

double Group::countAverageMark()
{
	double sum = 0;
	for (auto st : students)
	{
		sum += st->countAverageMark();
	}
	return sum / students.size();
}

Student* Group::findStudent(string name_to_find)
{
	for (auto st : students)
	{
		if (st->getStudentName() == name_to_find)
			return st;
	}
	return nullptr;
	
}

Student* Group::findStudent(int id_to_find)
{
	for (auto st : students)
	{
		if (st->getStudentId() == id_to_find)
			return st;
	}
	return nullptr;
}

void Group::expelStudentsWithBadMarks(double mark)
{
	int i = 0;
	bool headFlag = false;
	if (head->countAverageMark() <= mark)
		headFlag = true;
	for (int i = 0; i < students.size(); i++)
		if (students[i]->countAverageMark() < mark) {
			students.erase(students.begin() + i);
			i--;
		}
	if (headFlag)
	{
		this->appointHead();
	}
}

void Group::expelStudent(int index)
{
	students.erase(students.begin() + index - 1);
}

vector<Student*> Group::getStudents()
{
	return students;
}

string Group::getHeadName()
{
	return head->getStudentName();
}