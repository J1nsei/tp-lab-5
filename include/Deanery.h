#pragma once
#include<iostream>
#include<vector>
#include"Student.h"
#include"Group.h"
class Deanery
{
private:
	vector<Group*> groups;
	int last_free_id = 0;
public:
	int total_num_of_stud();
	void rand_heads();
	void create_student(const string& name, const string& title);
	void create_group(const string& title, const string& spec);
	void create_groups_f(const string& fname);
	void print_marks();
	void rand_marks();
	void transfer(const int& id, const string& origin_group, const string& destination_group);
	Group* find_group(const string&);
	double average_ball_all();
	void expel(const string& title, const int& id);
	void remove(const string& title, const int& id);
	void assign_head(const string& title, const int& id);
	void print_statistics();
	void output_data(const string& fname);
	void print_student_info(const string& title, const int& id);
};