#pragma once
#include <vector>
#include <string>
//#include "Group.h" this one doesn't work for some reason 
class Group;

class Student {
	friend class Group;
	friend class Deanery;
private:
	int id;
	std::string fio;
	Group* group_p;
	std::vector<int> marks;	
	void setGroup(Group* group_p);
public:
	Student(int id, std::string fio);
	int getId();
	std::string getFio();
	Group* getGroup_p();
	std::vector<int> getMarks();	
	void addMark(unsigned int mark);
	double averageMark();
};