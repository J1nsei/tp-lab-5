#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Group.h"

using namespace std;

class Group;

class Student {
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;
	int num;
	Student(int id, string fio);
	int addMark(int mark);
	int setGroup(Group* group);
	double getAvr();
public:
	string getFio();
	int getId();
	Group* getGroup();
	friend class Group;
	friend class Deanery;
};