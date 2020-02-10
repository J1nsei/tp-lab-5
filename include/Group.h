#pragma once
#ifndef GROUP_H
#define GROUP_H
#include "Student.h"

class Group {
private:
	string name;
	string spec;
	Student head;
	vector<Student> students;
public:
	Group(string);
	string getName();
	void addStudent(const Student);
	void setMarks();
	double averageMark();
	void setHead();
	Student* findStudent(const string);
	Student* findStudent(const int);
	void allocation();
	Student transferFrom();
	void scholarship(); 
	vector<Student> getStudents();
	string getSpec();
};
#endif 
