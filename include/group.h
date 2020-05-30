#pragma once 


#include "Header.h"
#include"student.h"

class Student;

class Group
{
public:
	Group(string title);
	~Group();

	void addStudent(Student* student);

	void setTitle(string title);
	void setHead(Student* student);
	void setRandHead();
	void setSpec(string spec);

	void setRandMarks();
	int getMeanMark();

	string getTitle();
	string getSpec();
	Student* getHead();

	void printStudents();
	void saveStudents(ofstream& out);
	void printStatistic();

	Student* findStudent(string fio);
	Student* findStudent(int id);

	Student* findLooser();
	void studentExpell(Student* s);

private:
	string title;
	string spec;
	Student* head;
	vector<Student*> students;
};


