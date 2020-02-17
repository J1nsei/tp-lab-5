#pragma once
#include<vector>
#include<string>
#include"Group.h"

using namespace std;

class Group;

class student {
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;
public:
	int getId();
	string getFio();
	Group* getGroup();
	vector<int> getMarks();

	student(string newFio, int newId);
	void changeGroup(Group* newGroup);
	void addMark(int mark);
	int getAverage();
};
