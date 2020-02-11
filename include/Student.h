#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Group;
class Deanery;

class Student {
private:
	string fio;
	Group* group;
	vector<int> marks;
	int id;
public:
	Student(string fio, int id);
	void addMark(int mark);
	void addStudentToGroup(Group* group);
	void deleteGroup();
	double averageMark(); 
	string getName() const;
	int getId() const;
	Group* getGroup() const;
	vector<int> getMarks() const;
};