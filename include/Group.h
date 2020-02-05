#pragma once
#include "Student.h"
#include <string>
#include <vector>
using namespace std;
class Group {
private:
	string title;
	string spec;
	vector<Student*> students;
	Student* head = NULL;
public:
	Group(string title, string spec);
	void AddStudent(string fio);
	void AddStudent(Student* student);
	void ChooseHead();
	double CalcAverage();
	void AddRandMarks(int num);
	void PrintStat();
	void ExpelStudent(string fio);
	void ExpelStudent(int id);
	Student* FindStudent(string fio);
	Student* FindStudent(int id);
	string GetTitle();
	void Expulsion(double points);
	void SaveData();
	void PrintInfo();
};