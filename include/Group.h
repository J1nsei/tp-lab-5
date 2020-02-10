#pragma once
#include<iostream>
#include<vector>
#include"Student.h"
#include"Deanery.h"
using namespace std;

class Group
{
private:
	string title;
	string spec;
	vector<Student*> students;
	Student* head;
	Group(const string& name, const string& spec);
	void add(Student*);
	void expel(Student*);
	void assign_head(Student*);
	friend class Deanery;
	
public:	
	int size();
	Student* find_id(const int&);
	vector<Student*> find_name(const string&);
	double average_ball();
	

};