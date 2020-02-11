
#include"student.h"

Student::Student(int id, string fio)
{
	this->id = id;
	this->fio = fio;
}

void Student::set_mark(int mark)
{
	marks.push_back(mark);
}

float Student::average_mark()
{
	float sum = 0;
	for (auto mark : marks)
	{
		sum += mark;
	}
	return sum / marks.size();
}

string Student::getFio()
{
	return fio;
}

int Student::getId()
{
	return id;
}

void Student::set_group(Group* group)
{
	this->group = group;
}

/*
void * Student::change_group(Group * n_group)
{
group = n_group;
return group;
}
*/

Group* Student::getGroup()
{
	return group;
}

vector<int> Student::getMarks()
{
	return marks;
}