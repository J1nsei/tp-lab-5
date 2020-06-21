#pragma once
#include <string>
#include <vector>
#include "student.h"
using namespace std;


class Group
{
private:
	string title, spec;
	vector<Student*> students;
	Student* head;
	friend class Deanery;
public:
	Group(string title, string spec);
	void addStudent(Student* student);
	void headChoice(Student* head);
	Student* searchStudentFIO(string fio);
	Student* searchStudentID(int id);
	double middleGroupMark(Group* group);
	void byeStudent(Student *student);
	string info();
};