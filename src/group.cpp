#define _CRT_SECURE_NO_WARNINGS
#include "group.h"
#include "dean.h"
#include <ctime>

Group::Group(string init_name)
{
	name = init_name;	
	spec = init_name.assign(init_name, init_name.find("-") + 1, init_name.size() - 1);
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
	double students_marks = 0;
	for (int i = 0; i < students.size(); i++) {
		students_marks += students[i].averageMark();
	}
	return (students_marks / students.size());
}

void Group::setHead() {
	srand(time(NULL));
	unsigned int random_student = rand() % students.size();
	head = students[random_student];
}

Student* Group::findStudent(string student_name) {
	for (auto& student : students) {
		if (student.getName() == student_name)
			return &student;
	}
	return nullptr;
}

Student* Group::findStudent(int student_id) {
	for (auto& student : students) {
		if (student.getId() == student_id)
			return &student;
	}
	return nullptr;
}

void Group::allocation() {
	// Проверяем список всех студентов
	for (int i = 0; i < students.size(); i++) 
		if (students[i].averageMark() < 2.5) {
			students.erase(students.begin() + i);
			i--;
		}
	// Проверяем старосту
	if (head.averageMark() < 2.5) {
		head.~Student();
		setHead();
	}
}

Student Group::transferFrom() {
	srand(time(NULL));
	unsigned int random_student = rand() % students.size();
	Student transferring_student = students[random_student];
	students.erase(students.begin() + random_student);
	if (head.getId() == transferring_student.getId()) {
		head.~Student();
		setHead();
	}
	return transferring_student;
}

void Group::scholarship() { 
	for (auto& student : students)
		if (student.averageMark() >= 4)
			cout << student.getName() << endl;
}

vector<Student> Group::getStudents() {
	return students;
}