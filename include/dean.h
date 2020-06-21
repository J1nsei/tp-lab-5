#pragma once
#include <vector>
#include "group.h"
#include <string>

using namespace std;

class Deanery
{
private:
	int lastId;
	vector<Group*> groups;
public:
	void crStudents(string path);
	void crGroups(string path);
	void addRandMarks();
	void getStats();
	void studTransfer(Group* group, Student* stud);
	void ripLazyStud();
	void saveNewData();
	void choiceGrHead();
	void printData();
};