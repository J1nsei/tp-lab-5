#include "student.h"
#include <ctime>

unsigned int new_id = 0;
const unsigned int number_of_marks = 10;

Student::Student(string init_name, string init_group) {
	name = init_name;
	group = init_group;
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
	double marks_counter = 0;
	for (int i = 0; i < number_of_marks; i++)
		marks_counter += marks[i];
	return (marks_counter / number_of_marks);
}

string Student::getName() {
	return name;
}

unsigned int Student::getId() {
	return id;
}

string Student::getGroup() {
	return group;
}

vector<int> Student::getMarks() {
	return marks;
}