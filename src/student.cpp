#include"Student.h"


int student::getId() {
	return id;
}

string student::getFio() {
	return fio;
}

Group* student::getGroup() {
	return group;
}

vector<int> student::getMarks() {
	return marks;
}

student::student(string newFio, int newId) {
	fio = newFio;
	id = newId;
}

void student::changeGroup(Group* newGroup) {
	group = newGroup;
}

void student::addMark(int mark) {
	marks.push_back(mark);
}

int student::getAverage() {
	int sum = 0;
	for (int i = 0; i < marks.size(); i++) {
		sum += marks[i];
	}
	return sum / marks.size();
}