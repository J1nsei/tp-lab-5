
#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Group {
	friend Student;
private:
	string title;
	vector<Student> students;
	Student head;
	size_t size;
public:
	string get_title();
	Group(string);
	Student get_head();
	void add_Student(const string&);
	void add_head(int);
	Student* search_Student(const string&);
	Student* search_Student(const int);
	double group_average_mark(); 
	void Delete_students(const string);
	void Delete_students(const int);
	size_t get_size() const;
};

#endif