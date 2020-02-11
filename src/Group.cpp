#include <time.h>
#include "group.h"

Group::Group(string name, string spec) {
	this->name = name;
	this->spec = spec;
}

string Group::getGroupName() const {
	return name;
}

string Group::getGroupSpec() const {
	return spec;
}

Student* Group::getGroupHead() const {
	return head;
}

vector<Student*> Group::getGroupStudents() const {
	return students;
}

Student* Group::chooseHead() {
	srand(time(NULL));
	head = students[rand() % students.size()];
	return head;
}

Student* Group::findStudent(string name) {
	for (auto student : students)
		if (student->getName() == name)
			return student;
	return nullptr;
}

Student* Group::findStudent(int id) {
	for (auto student : students)
		if (student->getId() == id)
			return student;
	return nullptr;
}

void Group::addStudent(Student* student) {
	students.push_back(student);
	students[students.size() - 1]->addStudentToGroup(this);
}

void Group::removeStudent(Student* student) {
	if (students.size() == 0) return;
	for (int i = 0; i < students.size(); i++)
		if (students[i]->getId() == student->getId()) {
			students.erase(students.begin() + i);
			student->deleteGroup();
			return;
		}
}

double Group::averageGroupMark() {
	if (students.size() == 0) return 0;
	double average = 0;
	for (auto & student : students)
		average += student->averageMark();
	return average / students.size();
} 