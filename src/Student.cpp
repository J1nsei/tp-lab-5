#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <time.h> 
#include "Student.h"
using namespace std;

Student::Student(int id, string fio) {
	this->id = id;
	this->fio = fio;
}

int Student::getId() {
	return id;
}

string Student::getFio() {
	return fio;
}
Group* Student::getGroup_p() {
	return group_p;
}

vector<int> Student::getMarks() {
	return marks;
}


void Student::setGroup(Group* group_p) {
	this->group_p = group_p;
}

void Student::addMark(unsigned int mark) {
	marks.push_back(mark);
}

double Student::averageMark() {
	double sum = 0;
	for (int i = 0; i < marks.size(); i++) {
		sum += marks[i];
	}
	return sum / marks.size();
}