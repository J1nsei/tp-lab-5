#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

using namespace std;

void Student::addMark(int mark) {
	marks[mark - 1]++;
}

double Student::averageMark() {
	double average = 0, _counter = 0;
	for (int i = 0; i < 10; i++) {
		average += marks[i] * (i + 1);
		_counter += marks[i];
	}
	return average /= _counter;
}

void Student::randomMarks() {
	for (int i = 0; i < 10; i++) {
		marks.push_back(0);
	}

	for (int i = 0; i < rand() % 10 + 5; i++) {
		marks[rand() % 9 + 1]++;
	}
}

void Student:: showMarks() {
	for (int i = 0; i < marks.size(); i++) {
		for (int j = 0; j < marks[i]; j++) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}

//int Student::getLastId() {
//	return group->getLastStudentId();
//}

int Student::getId() {
	return studentID;
}

string Student::getFIO() {
	return fio;
}

void Student::addToGroup(Group* _link) {
	group = _link;
}

void Student::setId(int id) {
	this->studentID = id;
}

void Student::deleteMarks() {
	for (int i = 0; i < 10; i++) {
		marks[i] = 0;
	}
}