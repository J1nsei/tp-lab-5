#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "student.h"
#include "group.h"
class Student;
class Group;
class Dean {
	friend Student;
	friend Group;
public:
	Dean();
	void create_group(std::string fname);
	void create_student(std::string fname);
	void add_marks(int n);
	void check_info();
	void moving(Student *s, Group *to);
	void expuls();
	void to_file();
	void chose_head();
	Student* get_S(int n);
	Group* get_G(int n);
private:
	std::vector<Student*> students;
	std::vector<Group*> groups;
};