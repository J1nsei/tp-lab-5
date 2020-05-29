#pragma once
#include <string>
#include <vector>
#include "Group.h"
using namespace std;

class Student
{
private:
	int id;
	string fio;
	class Group* group;
	vector<int> marks;
	
public:
	Student();
	Student(string fio,Group* group, int id);
	~Student();
	int getId();
	string getFio();
	Group* getGroup();
	vector<int> getMarks();
	void addMarks(int mark);
	double getMean();
	void addMark(int mark);
};

