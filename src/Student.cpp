#include "Student.h"

using namespace std;


Student::Student()
{
	id = 0;
	group = NULL;
}
Student::~Student()
{
	marks.clear();
}
Student::Student(string fio, Group* group, int id)
{
	this->fio = fio;
	this->group = group;
	this->id = id;
}
void Student::addMarks(int mark)
{
	marks.push_back(mark);
}
double Student::getMean()
{
	int	mean = 0;
	for (int i : marks)
		mean += i;
	return double(mean / marks.size());
}
int Student::getId()
{
	return id;
}
string Student::getFio()
{
	return fio;
}
Group* Student::getGroup()
{
	return group;
}
vector<int> Student::getMarks()
{
	return marks;
}
void Student::addMark(int mark)
{
	marks.push_back(mark);
}


