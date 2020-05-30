#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>     
#include <time.h> 
#include "Group.h"
using namespace std;

Group::Group(string title, string spec) {
	this->title = title;
	this->spec = spec;
}

string Group::getTitle() {
	return title;
}

string Group::getSpec() {
	return spec;
}

vector<Student*> Group::getStudents_p() {
	return students_p;
}

Student* Group::getHead() {
	return head;
}

void Group::addStudent(Student* student) {
	student->setGroup(this);
	students_p.push_back(student);
}

void Group::chooseHead(Student* student) {
	head = student;
}

Student* Group::searchStudent(int id) {
	for (int i = 0; i < students_p.size(); i++) {
		if (id == students_p[i]->id) {
			return students_p[i];
		}
		//else if (i == students_p.size() - 1 && students_p[i]->id != id) {
			//return NULL;
		//}
	}

}

Student* Group::searchStudent(string fio) {
	for (int i = 0; i < students_p.size(); i++) {
		if (fio == students_p[i]->fio) {
			return students_p[i];
		}
		//else if (i == students_p.size() - 1 && students_p[i]->fio != fio) {
			//return NULL;
		//}
	}
}

double Group::averageMarkGroup() {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < students_p.size(); i++) {
		for (int j = 0; j < students_p[i]->marks.size(); j++) {
			sum += students_p[i]->marks[j];
			count++;
		}
	}
	return sum / count;
}

void Group::removeStudent(int id) {
	for (int i = 0; i < students_p.size(); i++) {
		if (id = students_p[i]->id) {
			students_p.erase(students_p.begin() + i);
			return;
		}
	}
}

void Group::removeStudent(string fio) {
	for (int i = 0; i < students_p.size(); i++) {
		if (fio == students_p[i]->fio) {
			students_p.erase(students_p.begin() + i);
			return;
		}
	}
}