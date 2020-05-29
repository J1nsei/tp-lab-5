#pragma once
#ifndef GROUP_H
#define GROUP_H
#include "student.h"

class Group {
	private:
		string name;
		string spec;
		Student* head;
		vector<Student*> students;
	public:
		Group(string);
		string getName();
		void addStudent(Student*);
		void setMarks();
		void appointHead();
		double countAverageMark();
		void expelStudentsWithBadMarks(double);
		Student* findStudent(string);
		Student* findStudent(int);
		void expelStudent(int);
		vector<Student*> getStudents();
		string getHeadName();
};
#endif