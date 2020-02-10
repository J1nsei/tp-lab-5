#pragma once
#include <string>
#include <vector>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Group;

class Student
{
private:
	int id;
	string name;
	Group* group;
	vector<unsigned int> marks;
public:
	Student(string name, unsigned int id);
	unsigned int AverageMark() const;
	void addMark(unsigned int newMark);
	string getName() const;
	string getGroup() const;
	unsigned int getId() const;
	void setGroup(Group* newGroup); 
};



#endif