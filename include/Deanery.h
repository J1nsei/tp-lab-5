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
    vector<Student*>VseStud;
    string FileStud;
    string FileGrp;
    vector<pair<float, string>> StatStud;
    vector<pair<float, string>> StatGroup;

public:
	Deanery(string file_students, string file_groups);
	void MakeStudents();
	void MakeGroups();
	void AddMarks();
	void HeadInit();
	void Statistic(ostream* stream);
	void StudentDelete();
	void ChangeGroup(Student* stud, string title_target_group);
	void New();
	void PrintInf();

};