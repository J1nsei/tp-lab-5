#include "Student.h"
#include <iostream>


Student::Student()
{
	id = 0;
	fio = "Unknown";
	group = 0;
}

Student::Student(unsigned int data_id, std::string data_fio) {
	id = data_id;
	fio = data_fio;
	group = 0;
}

Student::~Student() {}

void Student::setID(unsigned int data_id) {
	id = data_id;
}

unsigned int Student::getID() {
	return id;
}

void Student::setFIO(std::string data_fio) {
	fio = data_fio;
}

std::string Student::getFIO() {
	return fio;
}

void Student::setGroup(Group* data_group) {
	if (data_group != 0) {
		group = data_group;
	}
}

Group* Student::getGroup() {
	return group;
}

void Student::addMark(int mark) {
	marks.push_back(mark);
}

double Student::averageMark() {
	int sum = 0;
	for (int i : marks) {
		sum += i;
	}
	if (marks.size() != 0) {
		return sum / marks.size();
	}
	else {
		//std::cout << "marks are not found" << std::endl;
		return 0.;
	}
}

