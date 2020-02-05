#pragma once
#include <string>
#include <vector>
using namespace std;
class Group;
class Student {
private:
	int id;
	string fio;
	Group *group = NULL;
	vector<int> marks;
public:
	Student(int id, string fio, Group* group);
	void SetGroup(Group *group);
	void AddMark(int mark);
	double CountAverage();
	void GetSumNum(int* sum, int* num);
	string GetFio();
	int GetId();
	void DecId();
	void SetId(int id);
	void PrintInfo();
};