#include "Group.h"
#include <algorithm>

Group::Group(string title) {
	this->title = title;
	this->head = NULL;
	num = 0;
}

int Group::addStudent(Student* student) {
	if (student == NULL || searchStudent(student->getId()) == student) {
		return -1;
	}
	students.push_back(student);
	student->setGroup(this);
	num++;
	return 1;
}

int Group::setHead(Student* student) {
	if (student == NULL) {
		return -1;
	}
	if (searchStudent(student->getId()) == student) {
		head = student;
		return 1;
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
		int count;
		for (auto &i_student: students){
			if (i_student == student){
				students.erase(students.begin()+count);
				break;
			}
			else{
				count += 1;
			}
		}
		if (head == student) {
			head = NULL;
		}
		num--;
		return 1;
	}
	else
		return -1;
}

vector<int> Group::getMarks(Student* student) {
	return vector<int>(student->marks);
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
