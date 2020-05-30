#pragma once
#include "Student.h"
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Student;
class Deanery;


class Group
{
	friend Deanery;

private:
	string title;
	string spec;
	vector<Student*> students;
	Student* head;
	
public:
	Group(string);
	void AddStudent(Student*);
	void ChooseHead();
	Student* findStudentId(int);
	double MiddleGroupMark();
	void ExStudent(int id);




};
