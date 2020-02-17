#pragma once
#include"Group.h"
#include<vector>

using namespace std;

class Deanery {
private:
	vector<Group> groups;
public:
	vector<Group> getGroups();
	void CreateStudents(const string& name);
	void addGroup(Group group);
	void GenerateMarks(const string& groupName);
	Group* findGroup(const string& groupTitle);
	int GetStatsGroup(const string& groupTitle);
	int GetStatsStudent(int id);
	void MoveStudent(const string& groupTitle1, const string& groupTitle2, string name);
	void CickStudents();
	void Print();
	void ChooseHead();
	void Save(const string name);
};