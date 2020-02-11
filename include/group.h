#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "student.h"
#include "dean.h"
class Dean;
class Student;
class Group {
	friend Dean;
	friend Student;
private:
	std::string name;
	std::string spec;
	std::vector<Student*> students;
	Student* head;
public:
	Group(std::string name);
	void add_student(Student*);
	std::string get_name();
	//void set_head(unsigned int id);
	//void set_head();
	Student* set_head();
	Student* find_student(unsigned int id, std::string fio);
	Student* find_student(unsigned int id);
	Student* find_student(std::string fio);
	float average();
	/*void exclude(unsigned int id, std::string fio); */  // type of
	bool exclude(unsigned int id);                    // returnable
	bool exclude(std::string fio);                    // param ???

};