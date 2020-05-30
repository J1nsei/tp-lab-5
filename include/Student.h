#pragma once
#include <string> 
#include <vector>

using namespace std;

class Student
{
private:
	int id;
	string fio;
	string group;
	vector<int> marks;
public:
	friend class Group;
	friend class Deanery;
	Student(int id_, string fio_);
	void AddToGroup(string group_);
	void AddMark();
	double AvMark();
	int MarkSize();
	string GetFio();
	int GetId();
};