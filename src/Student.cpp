#include "Student.h"

Student::Student(string fio, int id) {
	this->id = id;
	this->fio = fio;
}

string Student::getName() const {
	return fio;
}

int Student::getId() const {
	return id;
}

Group* Student::getGroup() const {
	return group;
}

vector<int> Student::getMarks() const {
	return marks;
}

void Student::addStudentToGroup(Group *group) {
	this->group = group;
}

void Student::deleteGroup() {
	group = nullptr;
}

void Student::addMark(int mark) {
	marks.push_back(mark);
}

double Student::averageMark() {
	double sum = 0;
	for (auto & n : marks)
		sum += n;
	return sum / marks.size();
}
