#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "group.h"
#include "dean.h"
class Dean;
class Group;
class Student {
	friend Dean;
	friend Group;
private:
	unsigned int id;
	std::string fio;
	Group* group;
	std::vector <int> marks;
public:
	Student(unsigned int id, std::string fio);
	void add_group(Group* group);
	void add_mark(int);
	float average();
	void get_marks();
	int get_id();
};