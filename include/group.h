
#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Group
{
	friend class Deanery;
private:
	string title;
	string spec;
	Student* head;
	vector<Student *>students;
public:
	Group(string title, string spec);
	void add_student(Student* student);
	void choose_head();
	Student * find_student_fio(string fio);
	Student * find_student_id(int id);
	float average_mark();
	void delete_student(Student* student);

	string getTitle();
	string getSpec();
	vector<Student*> getStudents();
	Student* getHead();
};

#endif