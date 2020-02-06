#pragma once //fix
#include <string> 
#include <vector>
#include "Student.h"
using namespace std;

class Group
{
public:
	friend class Deanery;
	Group(string title_); 
	void AddStudent(Student*student_); 
	Student* HeadElection(); 
	Student* SearchStudent(int id_); 
	double AverageGroup();
	void DeleteStudent(int id_); 
	int GetSize();
private:
	Student* head;
	string title;
	vector<Student*>students;
};