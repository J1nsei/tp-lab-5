#pragma once
#include <random>
#include <time.h>
#include "Student.h"
#include <string>

using namespace std;

class Group
{
private:
	string title;
	vector<class Student*> students;
	Student* head;
	
public:
	Group();
	Group(string title);
	~Group();
	string getTitle();
	vector<Student*> getStudens();
	Student* getHead();
	Student* getStudentById(int id);
	Student* getStudentByName(string fio);
	double getMeatMark();
	void addStudent(class Student* student);
	Student* chouseNewHead();
	void killStudent(Student* student);
	void killStudent(int id);
	void killStudent(string fio);

};

