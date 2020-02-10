#pragma once
#include "Group.h"
#include <vector>
#include <cstring>
#include <string>


using namespace std;


class Deanery
{

private:

	vector<Group*> groups;
	
public:
	Deanery();
	void CreateGroup();
	void AddStudentMark();
	void StatisticGroup();
	void ReChooseHeaders(string);
	void DeductStudents();
	void Console();
	void ReplaceStudent(int name, string groupnamefrom, string groupnameto);

};
