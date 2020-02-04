#include "Student.h"

using namespace std;

Student::Student(int id, string fio) {
	this->id = id;
	this->fio = fio;
	this->group = NULL;
	this->num = 0;
}

int Student::addMark(int mark) {
	if (mark >= 0 && mark < 11) {
		marks.push_back(mark);
		num++;
		return 0;
	}
	else {
		return -1;
	}
}

double Student::getAvr() {
	if (this->num == 0) {
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum = sum + marks[i];
	return (double)sum / num;
}

int Student::setGroup(Group* group) {
	if (group == NULL) {
		return -1;
	}
	this->group = group;
	return 0;
}

string Student::getFio() {
	return fio;
}

int Student::getId() {
	return id;
}

Group* Student::getGroup()
{
	return group;
}