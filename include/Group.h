#pragma once
#include <iostream>
#include "Student.h"
#include <vector>
#include <string>

class Student;
class Dean;

class Group {
	friend class Dean;
	friend class Student;
private:
	std::string title;
	std::string spec;
	std::vector <Student> students;
	Student* head;
public:
	Group(std::string, std::string);
	void addstudent(Student);
	void headman();
	Student* search_student_id(int id);
	Student search_student_name(std::string name);
	double average_score();
	void kick_from_group(Student);
	std::string get_title();
};
