#pragma once
#include <string>
#include <vector>
#include "student.h"



class Group
 {   
public:
	friend class Decan;
	explicit Group(std::string name);
	void addStudent(Student* student);
	Student* setHead();
	Student* findStudent(int ID);
	double getAverage();
	void kickStudent(int ID);
	int getSize();

private:
	std::string groupName;
	std::vector <Student*> student;
	Student* head;
};
