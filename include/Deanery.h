#pragma once
#include <string> 
#include <vector>
#include "Student.h"
#include "Group.h"
using namespace std;

class Deanery
{
private:
	vector<Group*>groups;
	vector<Student*>AllStudents;
	string FileStud;
	string FileGrp;
	vector<pair<float, string>> StatStud;
	vector<pair<float, string>> StatGroup;

public:
	Deanery(string file_students, string file_groups);
	void CreateStudents();
	void CreateGroups();
	void AddMarks();
	void Statistic(ostream* stream);
	void ChangeGroup(Student* stud, string title_target_group);
	void StudentDelete();
	void New();
	void HeadInit();
	void PrintInformation();

};