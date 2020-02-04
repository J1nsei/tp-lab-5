#pragma once
#include "Student.h"
#include "Deanery.h"

using namespace std;

class Student;

class Group {
private:
	string title;
	int num;
	Student* head;
	vector<Student*> students;
	Group(string title);
	int addStudent(Student* student);
	int setHead(Student* student);
	vector<Student*> searchStudent(string fio);
	Student* searchStudent(int id);
	int eraseStudent(Student* student);
	vector<int> getMarks(Student*);
public:
	double getAvr();
	string getTitle();
	int getNum();
	Student* getHead();
	friend class Deanery;
};