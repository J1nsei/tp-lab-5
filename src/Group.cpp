#include "Group.h"
#include <iostream>
#include <vector>

Group::Group()
{
	name = "group0";
	head = 0;
}

Group::Group(std::string data_name) {
	name = data_name;
	head = 0;
}

Group::~Group() {}

std::string Group::getName() {
	return name;
}

void Group::addStudent(Student* student) {
	if (student != 0) {
		students.push_back(student);
	}
}

void Group::expelStudent(Student* student) {
	//if head == student
	if (student != 0) {
		if (student == head) {
			head = 0;
		}
		for (auto iter = students.begin(); iter != students.end(); ++iter) {
			if (*iter == student) {
				students.erase(iter);
				break;
			}
		}
	}
	else {
		std::cout << "Student is not found" << std::endl;
	}	
}

void Group::setHead(Student* student) {
	if (student != 0 && findStudentById(student->getID() != 0)) {
		head = student;
	}
}

Student* Group::getHead() {
	return head;
}

Student* Group::findStudentByName(std::string name) {
	for (Student* student : students) {
		if (student->getFIO() == name) {
			return student;
		}
	}
	return 0;
}

Student* Group::findStudentById(unsigned int id) {
	for (Student* student : students) {
		if (student->getID() == id) {
			return student;
		}
	}
	return 0;
}

double Group::averageMark() {
	double sum = 0.;
	for (Student* student : students) {
		sum += student->averageMark();
	}
	if (students.size() != 0) {
		return sum / students.size();
	}
	else {
		std::cout << "Students are not found" << std::endl;
		return 0.0;
	}
}

