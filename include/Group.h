#ifndef groupH
#define groupH

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Student.h"

using namespace std;

class Group
{
private:
	string title;
	vector<Student*> students;
	Student* head;

public:
	Group(string title);

	void addStudent(Student*student);

	Student* headman();

	Student* searchStudent(int ID);

	double averageMarkGroup();

	void deleteStudent(int ID);

	friend class Deanery;

	int studSize();
};
#endif