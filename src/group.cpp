#include"Group.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string  Group::getTitle() {
	return title;
}

string Group::getSpec() {
	return spec;
}

student* Group::getHead() {
	return head;
}

vector<student>& Group::getStudents() {
	return students;
}

Group::Group(string NewTitle, string NewSpec) {
	title = NewTitle;
	spec = NewSpec;
}

void Group::addStudent(student& newStudent) {
	students.push_back(newStudent);
}

void Group::newHead(student* newHead) {
	head = newHead;
}

void Group::cickStudent(student& student) {
	int index = 0;
	for (int i = 0; i < students.size(); i++) {
		if ((student.getId())==(students[i].getId())) {
			index = i;
			break;
		}
	}
	students.erase(students.begin() + index);
}

int Group::getAverage() {
	int sum = 0;
	for (int i = 0; i < students.size(); i++) {
		sum += students[i].getAverage();
	}
	return sum / students.size();
}

student* Group::findStudent(int id) {
	for (int i = 0; i < getStudents().size(); i++) {
		if ((students[i].getId()) == id) {
			return &students[i];
		}
	}
	return nullptr;
}

student* Group::findStudent(string fio) {
	for (int i = 0; i < getStudents().size(); i++) {
		if ((students[i].getFio()) == fio) {
			return &students[i];
		}
	}
	return nullptr;
}
