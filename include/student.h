#pragma once
#include <string>
#include <vector>
#include <iostream>



class Student
{

public:
	friend class Group;
	friend class Decan;
	Student(std::string name, int ID);
	unsigned int getID();
	std::string getName();
	void add(std::string group);
	void setMarks(int mark);
	std::vector<int>& getMark();
	unsigned long getAverage();
	unsigned int ID;

private:
	
	std::string name;
	std::string group;
	std::vector<int> marks;
};
