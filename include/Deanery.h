#pragma once
#include "Group.h"
#include "Student.h"
#include <fstream> 
#include <ctime>
using namespace std;

class Group;
class Student;

class Deanery {
private:
	vector<Group*> groups;
	static int getId();
	int createStudent(string group, string student);
public:
	Deanery();
	int extractDataFromFile(string fileName);
	Group* searchGroup(string groupName);
	Student* searchStudent(int id);
	vector<Student*> searchStudent(string student);
	void randMarks();
	void getStatistics();
	int eraseWithBadMarks(double min_mark);
	int changeGroup(Student* student, Group* group);
	int saveDataInFile(string filename);
	void electionHead();
};
