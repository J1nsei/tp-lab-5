#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Group;
class Student
{
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;

public:
	Student(int id_, string fio_);
	void change_group(Group* new_group);
	void set_mark(int mark_);
	float average_mark();

	int get_id();
	string get_fio();
	Group * get_group();

	friend class Deanery;
};
