#pragma once

#include <string>
#include <vector>
#include "student.h"

using namespace std;

#ifndef GROUP_H
#define GROUP_H

class Student;

class Group
{
private:
	string groupName;
	string spec;
	vector <Student*> students;
	Student* head;
public:
	Group(string title, string specName);
	void addStudent(Student* newStudent);
	void expelStudent(Student* newStudent);
	void chooseHead();
	string getTitle() const;
	string getSpec() const;
	string getHeadName() const;
	vector<Student*> getStudents() const;
	unsigned int AverageMarkofGroup() const;
	Student * findbyName(string name) const;
	Student * findbyId(int id) const;
};


#endif