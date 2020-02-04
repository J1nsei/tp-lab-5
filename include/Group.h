#pragma once
#include "Student.h"

using namespace std;

class Student;

class Group {
private:
	string title;
	vector<Student*> students;
	int num;
	Student* head;

public:
	Group(string title);
	int addStudent(Student* student);
	int setHead(Student* student);
	vector<Student*> searchStudent(string fio);
	Student* searchStudent(int id);
	double getAvr();
	int eraseStudent(Student* student);

	string getTitle();
	int getNum();
	Student* getHead();
};