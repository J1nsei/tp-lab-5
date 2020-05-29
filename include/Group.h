#pragma once
#include<string>
#include "Student.h"

class Group
{
private:
	std::string name;
	std::vector<Student*> students;
	Student* head;
public:
	Group();
	Group(std::string name);
	~Group();
	std::string getName();
	void addStudent(Student* student);
	void expelStudent(Student* student);
	void setHead(Student* student);
	Student* getHead();
	Student* findStudentByName(std::string name);
	Student* findStudentById(unsigned int id);
	double averageMark();		
};

