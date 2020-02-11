#pragma once

#include <string>
#include <vector>
#include "student.h"

class Student;

class Group
{
private:
	std::string title;
	std::string spec;
	std::vector <Student*> students;
	Student* head;
public:
	Group(std::string title, std::string spec);
	void add_student(Student* student);
	Student* find(const std::string& name) const;
	Student* find(unsigned int id) const;
	void allocation(Student* newStudent);
	void elect_head();
	std::string get_title() const;
	std::string get_spec() const;
	std::string get_head() const;
	std::vector<Student*> get_students() const;
	float get_average_group() const;
};