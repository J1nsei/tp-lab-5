#pragma once //fix
#include <string>
#include <vector>
#include "Group.h"
#include "Student.h"
using namespace std;

class Deanery
{
public:
	Deanery(string file_students, string file_groups); 
	void MakeStudents(); 
	void MakeGroups(); 
	void AddMarks(); 
	void HeadInit(); 
	void Statistics(); 
	void StudentException(); 
	void ChangeGroup(Student *stud, string title_target_group); 
	void Update(string title_);
	void PrintData();
	int GetStudentsNumber();
private:
	vector<Group*>groups;
	vector<Student*>allstudents;
	string FileStudents;
	string FileGroups;
	vector<pair<float, string>> StatStud;
	vector<pair<float, string>> StatGroup;

};