#include <string>
#include <vector>
#include "Student.h"
#include <ctime>

class Group;
Student::Student(std::string name, int id)
{
	this->fio = name;
	this->id = id;
}

int Student::getId()
{
	return id;
}

void Student::add_to_group(Group* group)
{
	this->group = group;
}
void Student::add_mark()
{
	srand(time(nullptr));
	marks.push_back(1 + rand() % 10);
}
void Student::add_mark(int mark)
{
	marks.push_back(mark);
}
double Student::avg_mark()
{
	int fullmark = 0;
	for (auto mark : marks)
		fullmark += mark;
	return marks.size() != 0 ? fullmark / marks.size():0;
}

std::string Student::getname(){
	return fio;
}