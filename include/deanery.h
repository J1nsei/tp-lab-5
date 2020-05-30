#pragma once 


#include "Header.h"
#include "group.h"




class Deanery
{
public:
	Deanery();
	~Deanery();
	void createGroups();

	returns addGroup(Group* group);
	void printGroups();

	void setRandMarks();

	void printStatistic();
	void printStatisticDetailed();

	void transferStudent(Group* g_from, Group* g_to, Student* s);

	void chooseHeadsRand();
	void printHeads();

	void noLowMarks();

	void saveInform();

	Group* findGroup(string title);
	Student* findStudent(int id);


private:
	vector<Group*> groups;
	Student* createStudent(string fio, int id, Group* group);
};

