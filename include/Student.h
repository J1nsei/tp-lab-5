#ifndef studentH
#define studentH

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Student
{
private:
	unsigned int ID;
	string FIO;
	string group;
	vector<int> marks;

public:
	friend class Group;

	friend class Deanery;

	Student(int ID, string FIO);

	int getID();

	string getFIO();

	void addToGroup(string group);

	void setMarks(int mark);

	vector<int>& getMarks();

	int getAvarageMarks();
};
#endif