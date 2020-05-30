#pragma once
#include <string> 
#include <vector>
#include "Student.h"
using namespace std;

class Group
{
private:
	string title;
	string spec;
	vector<Student*>students;
	Student* head;

public:
	friend class Deanery;
	Group(string title_);
	void AddStudent(Student* Student_);
	Student* ChoiceHead();
	Student* SearchStudent(int id_);
	double AveMarkGroup();
	void DeleteStud(int id_);
	int GetSize();

};