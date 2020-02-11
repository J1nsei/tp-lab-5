
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Group;
class Student
{
	friend class Deanary;
private:
	int id;
	string fio;
	Group* group;
	vector<int> marks;

public:
	Student(int id, string fio);
	int getId();
	string getFio();
	void set_mark(int mark);
	float average_mark();
	void set_group(Group* group);

	vector<int> getMarks();
	Group* getGroup();
};

#endif