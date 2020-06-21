#pragma once
#include <string>
#include <vector>

using namespace std;

class Group;

class Student
{
private:
	int id;
	string fio;
	vector<int> marks;
	Group* group;
	friend class Deanery;
public:
	Student(int id, string fio);
	void addGroup(Group* group);
	void addMark(int mark);
	double middleMark();
	string getFio();
	int getId();
};