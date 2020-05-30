#pragma once

#include "Group.h"

class Deanery
{
private:
	vector<Group*> groups;

public:
	Deanery(string output);
	Group*  make_group(string title_);
	Student*  make_student(string fio_);

	void add_marks();
	void add_mark(int id_, int mark_);
	void add_mark(string fio_, int mark_);
	void add_mark(Student* student_, int mark_);

	float get_average_mark_student(string fio_);
	float get_average_mark_student(int id_);
	float get_average_mark_Group(string title_);

	bool transmit_student(Group* output, Group* input, int id_);
	bool transmit_student(Group *input, int id_);
	bool transmit_student(Group* output, Group* input, Student* student_);
	bool transmit_student(Group *input, Student* student_);
	bool transmit_student(Group* output, Group* input, string fio_);
	bool transmit_student(Group *input, string fio_);

	void remove_student();
	void choose_head_();
	void save_data(string input);

	bool add_group(Group* group_);
	bool add_student(Group* group_, Student* student_);

	Student* find_student(string fio_);
	Student* find_student(int id_);
	bool find_student(Student*student_);

	Group* find_student_in_group(int id_);
	Group* find_student_in_group(string fio_);
	Group* find_student_in_group(Student* student_);
	
	Group* find_group_title(string title_);
	Group* find_group_spec(string spec_);
	bool find_group(Group* group_);

	string small_check();
	void out_data_in_consol();

	friend int main();
};
