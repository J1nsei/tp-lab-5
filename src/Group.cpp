#define _CRT_SECURE_NO_WARNINGS
#include "group.h"
#include "dean.h"
#include <ctime>
#include <iostream>

Group::Group(string group_name)
{
	name = group_name;
	spec = group_name.assign(group_name, group_name.find("-") + 1, group_name.size() - 1);
}

string Group::getName() {
	return name;
}

string Group::getSpec() {
	return spec;
}

void Group::addStudent(Student new_student) {
	students.push_back(new_student);
}

void Group::setMarks() {
	for (int i = 0; i < students.size(); i++) {
		students[i].setMarks();
	}
}

double Group::averageMark() {
	double av_marks = 0;
	for (int i = 0; i < students.size(); i++) {
		av_marks += students[i].averageMark();
	}
	return (av_marks / students.size());
}

void Group::setHead() {
	srand(time(NULL));
	unsigned int rand_stud = rand() % students.size();
	head = students[rand_stud];
}

Student* Group::findStudent(string name) {
	for (auto& student : students) {
		if (student.getName() == name)
			return &student;
	}
	return nullptr;
}

Student* Group::findStudent(int id) {
	for (auto& student : students) {
		if (student.getId() == id)
			return &student;
	}
	return nullptr;
}

void Group::allocation() {
	
	for (int i = 0; i < students.size(); i++)
		if (students[i].averageMark() < 2.5) {
			std::cout << students[i].getName() << " was allocated! Sorry!" << std::endl;
			students.erase(students.begin() + i);
			i--;
		}
	
	if (head.averageMark() < 2.5) {
		head.~Student();
		setHead();
	}
}

Student Group::transferFrom() {
	srand(time(NULL));
	unsigned int rand_stud = rand() % students.size();
	Student transf_stud = students[rand_stud];
	students.erase(students.begin() + rand_stud);
	if (head.getId() == transf_stud.getId()) {
		head.~Student();
		setHead();
	}
	return transf_stud;
}

void Group::scholarship() {
	for (auto& student : students)
		if (student.averageMark() >= 4)
			cout << student.getName() << endl;
}

vector<Student> Group::getStudents() {
	return students;
}