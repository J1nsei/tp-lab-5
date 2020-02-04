#include "Group.h"

Group::Group(string title) {
	this->title = title;
	this->head = NULL;
	num = 0;
}

int Group::addStudent(Student* student) {
	if (student == NULL) {
		return -1;
	}
	if (searchStudent(student->getId()) == student) {
		return -1;
	}
	students.push_back(student);
	student->setGroup(this);
	num++;
}

int Group::setHead(Student* student) {
	if (student == NULL) {
		return -1;
	}
	if (searchStudent(student->getId()) == student) {
		head = student;
		return 0;
	}
	else {
		return -1;
	}
}

vector<Student*> Group::searchStudent(string fio) {
	vector<Student*> foundStudents;
	for (int i = 0; i < num; i++) {
		if ((students[i]->getFio() == fio)) {
			foundStudents.push_back(students[i]);
		}
	}
	return foundStudents;
}

Student* Group::searchStudent(int id) {
	for (int i = 0; i < num; i++) {
		if ((students[i]->getId() == id)) {
			return students[i];
		}
	}
	return NULL;
}

double Group::getAvr() {
	double sum = 0;
	if (students.empty()) {
		return 0;
	}

	for (int i = 0; i < num; i++) {
		sum = sum + (students[i]->getAvr());
	}

	return sum / num;
}

int Group::eraseStudent(Student* student) {
	if (student == NULL) {
		return -1;
	}
	Student* foundStudent = searchStudent(student->getId());
	if (foundStudent != NULL) {
		students.erase(find(students.begin(), students.end(), foundStudent));
		num--;
		return 0;
	}
	else
		return -1;
}

string Group::getTitle()
{
	return title;
}

int Group::getNum()
{
	return num;
}

Student* Group::getHead()
{
	return head;
}