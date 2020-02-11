
#ifndef DEANERY_H
#define DEANERY_H

#include "Student.h"
#include "group.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Deanery
{
private:
	vector<Group*> groups;
public:
	Deanery();
	void make_students(int id,string fio, Group* group);
	Group* make_groups(string title, string spec);
	void add_mark(Group* group, string student, int mark);
	float get_average_mark_student(Group* group, string student);
	float get_average_mark_group(Group* group);
	void change_group_for_student(string fio, Group* old_group, Group* new_group);
	void delete_student_for_poor_grades(Group* group);
	void save_new_data();
	void make_head(Group* group);
	void print_data();
};

#endif