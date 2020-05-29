#ifndef deaneryH
#define deaneryH

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>
#include"Group.h"

using namespace std;

class Deanery
{
private:
	vector<Group*> groups;
	vector<Student*> allTheStudents;
	string FileStudents;
	string FileGroups;
	vector<pair<float, string>> StatStud;
	vector<pair<float, string>> StatGroup;

public:
	Deanery(string fileStudents, string fileGroups);

	void makeStud();

	void makeGroups();

	void addMarks();

	void stat();

	void changeGroup(Student *stud, string titleOfGroup);
	
	void exclusion();

	void upd(string title_);

	void leader();

	void outputInform();

	int GetStudentsNumber();
};
#endif