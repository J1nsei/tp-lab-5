#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "student.h"
#include "group.h"

class Group;
class Student;

class Deanery
{
private:
	std::vector <Group*> groups;
	unsigned int d_id;
public:
	Deanery();
	void add_groups(std::string names_input, std::string groups_input);
	void set_marks(unsigned int num);
	void get_stat() const;
	void change_group(std::string name, std::string prev_group, std::string newGroup);
	void allocations();
	void save_data(std::string file_names, std::string file_groups) const;
	void elect_heads();
};
