#pragma once
#include "Group.h"
#include <fstream> 
#include <ctime>



class Deanery {
private:
	vector<Group*> groups;
	static int getId();
	int createStudent(string group, string student);
public:
	Deanery();
	void extractDataFromFile(string fileName);
	Group* searchGroup(string groupName);
	void randMarks();
	void getStatistics();
	//void changeGroup(Student* student, Group* groupFrom, Group* groupTo);
	int eraseWithBadMarks(double min_mark);
	//int saveData();
	void electionHead();
};
