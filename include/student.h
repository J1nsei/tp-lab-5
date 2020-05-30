#pragma once
#include <string>
#include <vector>

class Group;

class Student
{
private:
	unsigned int id;
	std::string name;
	Group* group;
	std::vector<unsigned int> marks;
public:
	Student(std::string name, unsigned int id);
	float get_average() const;
	void add_mark(unsigned int mark);
	std::string get_name() const;
	std::string get_group() const;
	unsigned int get_id() const;
	void set_group(Group* group);
};