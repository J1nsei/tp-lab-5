#pragma once //fix
#include <string> 
#include <vector>
using namespace std;

class Student
{
public:
	friend class Group;
	friend class Deanery;
	Student(int id_, string fio_);  
	void AddGroup(string group_); 
	void AddMark(int mark); 
	double AverageBall(); 
private:
	int id;
	string fio;
	string group;
	vector<int>marks;
};