#pragma once
#include <vector>
#include <string>
#include "group.h"
#include <algorithm>
#include <fstream>
#include <iostream>


class Decan 
{

public:
	Decan(std::string Students, std::string Groups);
	void addStudent();
	void addGroup();
	void setMarks();
	void changeGroup(Student* student, const std::string& group);
	void update(const std::string& fileName);
	void setHead();	
	void kickStudent();
	void printGroup();
	int countStudents();

private:
	std::vector<Group*> group;
	std::vector<Student*> student;
	std::string fstreamStudent;
	std::string fstreamGroup;
	std::vector<std::pair<float, std::string>> studentsMMark;
	std::vector<std::pair<float, std::string>> groupMMark;

};