#pragma once
#include <iostream>
#include "Group.h"
#include <vector>

class Group;

class Student {
	friend class Dean;
private:
	int id;
	std::string fio;
	Group* group;
	std::vector <int> marks;
public:
	Student(std::string, int);
	int getId();
	std::string getname();
	void add_to_group(Group*);
	void add_mark();
	void add_mark(int mark);
	double avg_mark();
};
