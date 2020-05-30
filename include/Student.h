#pragma once
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Group;
class Deanery;

class Student
{
	friend Group;
	friend Deanery;
private:

	int id;
	string fio;
	string group;
	vector<int> marks;

public:
	Student();
	Student(int, string,string);
	void AddGroup(string);
	void AddMark(int);
	double MiddleMark();
	



};
