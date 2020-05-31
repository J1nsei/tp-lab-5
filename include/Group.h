#pragma once
#include<vector>
#include<string>
#include"Student.h"

using namespace std;

class student;

class Group{
private:
	string title;
	string spec;
	vector<student> students;
	student* head;
public:
	string getTitle();
	string getSpec();
	student* getHead();
	vector<student>& getStudents();

	Group(string title, string spec);
	void addStudent(student& newStudent);
	void newHead(student* newHead);
	int getAverage();
	void cickStudent(student& student);
	student* findStudent(int id);
	student* findStudent(string fio);
};
