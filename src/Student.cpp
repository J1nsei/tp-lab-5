#include "student.h"
#include <ctime>

unsigned int new_id = 0;
const unsigned int number_of_marks = 10;

Student::Student(string stud_name, string stud_group) {
	name = stud_name;
	group = stud_group;
	id = ++new_id;
};

Student::Student() {
	name = "Unknown";
	group = "Unknown";
	id = -1;
}

void Student::setMarks() {
	for (int i = 0; i < number_of_marks; i++) {
		marks.push_back(rand() % 4 + 2);
	}
}

double Student::averageMark() {
	double cnt = 0;
	for (int i = 0; i < number_of_marks; i++)
		cnt += marks[i];
	return (cnt / number_of_marks);
}

string Student::getName() {
	return name;
}

int Student::getId() {
	return id;
}

string Student::getGroup() {
	return group;
}

vector<int> Student::getMarks() {
	return marks;
}