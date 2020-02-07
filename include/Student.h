#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student {
private:
	int id;
	string name;
	string group;
	vector<int> marks;
public:
	Student();   
	Student(int, const string&, const string&);
	void add_Group(string);
	void add_Mark(int);
	double average_Mark();
	int get_id();
	void set_id(int);
	string get_name();
	vector<int> get_marks();
};


#endif