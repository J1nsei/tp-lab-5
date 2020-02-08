#pragma once

#include <string>
#include <vector>

using namespace std;

class Group;

class Student{
	private:
		int id;
		string fio;
		Group* group;
		vector<int> marks;
	public:
		Student(string, int);
		void addToGroup(Group* group);
		void addMark(int);
		double getAverage();
		string getName();
		int getId();
		Group* getGroup();
		vector<int> getMarks();
};
