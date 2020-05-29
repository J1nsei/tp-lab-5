#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Student {
	private:
		string name;
		string group;
		unsigned int id;
		vector<int> marks;
	public:
		Student();
		~Student() {};
		Student(string, string);
		void setMarks();
		void setGroup(string);
		double countAverageMark();
		string getStudentName();
		string getStudentGroup();
		int getStudentId();
		void printInformation();
		vector<int> getMarks();
};
#endif