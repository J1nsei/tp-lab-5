#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
	string name;
	string group;
	int id;
	vector<int> marks;
public:
	Student();
	Student(const string, const string);
	~Student() {};
	void setMarks();
	double averageMark();
	string getName();
	int getId();
	vector<int> getMarks();
	string getGroup();
};
#endif 