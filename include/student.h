#pragma once 

#include "Header.h"
#include "group.h"

class Group;

class Student
{
public:
	Student(int id, string fio);
	~Student();
	
	void addToGroup(Group* group);
	
	void addMark(int mark);
	int meanMark();


	string getFIO();
	int getID();
	Group* getGroup();

	void setFIO(string fio);
	void setID(int id);

	bool is_head();

	void printStudentInf();

private:
	string fio;
	int id;
	vector <int>marks;
	Group* group;

};


