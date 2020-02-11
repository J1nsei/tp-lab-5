#pragma once
#include "Group.h"

class Dean {
private:
	std::vector<Group*> groups;
	std::string name;
	int id;
public:
	Dean(std::string);
	Group* search_group_name(std::string);
	void add_student_to_group(std::string fio, std::string group_name);
	void create_group(std::string, std::string);
	void add_mark_to_student(std::string group_name, std::string name, int mark);
	void move_students(int id, std::string group1, std::string group2);
	void kick_student(Student);
	void update_data(std::string);
	void init_head(std::string);
	void print_data();
};