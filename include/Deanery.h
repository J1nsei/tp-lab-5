#pragma once
#include "Group.h"

class Deanery {
private:
	vector<Group*> groups;
	int d_id = 0;
public:
	Deanery();
	void createGroups(string groups_file);
	void createStudents(string students_file);
	void addGroup(Group*);
	Group* findGroup(string group_name) const;
	void addMarks(int num);
	void setHeads();
	void removeStudents(double);
	void transferStudent(string fio, string to);
	void getStatistics();
	void saveData();
	vector<Group*> getGroups();

	friend Group;
	friend Student;
};
