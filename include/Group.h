#pragma once

#include "Student.h"

class Group
{
private:
	string title;
	vector<Student*> students;
	Student* head;
	string spec;

public:
	Group(string);

	void add_student_(Student*student_);
	void choose_head();

	bool student_in_group(Student*student_);
	bool student_in_group(int id_);
	bool student_in_group(string fio_);

	float average_score_in_group();

	bool remove_student_(int id_);
	bool remove_student_(string fio_);
	//bool remove_student_(Student* student);

	string get_title();
	string get_spec();
	string get_head();

	friend class Deanery;
};
