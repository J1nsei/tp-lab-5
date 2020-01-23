#pragma once
#include <iostream>
#include <string.h>
#include <vector>

#include "group.h"

using namespace std;

class Student
{
public:
	Student(int id, string fio);
	~Student();

	void addToGroup(Group& group);
	void addMark(int mark);
	int getMean();

private:
	int id;
	string fio;
	Group & group;
	vector<int> marks;
};

Student::Student(int id, string fio):
{
	this->id = id;
	this->fio = fio;
	

}

Student::~Student()
{
}
