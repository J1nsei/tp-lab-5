#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Group;
class Deanery;
class Student
{
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;
	void sign_up(Group* gr);
	Student(const int& id, const string& fio);
	void add_mark(const int& mark);
	friend class Deanery;
	friend class Group;

public:
	int get_id();
	string get_name();
	double average_mark();

};