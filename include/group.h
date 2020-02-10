#pragma once

#include <string>
#include <vector>
#include "student.h"


class Group{
	private:
		string title;
		string spec;
		vector<Student*> students;
		Student* head;
	public:
		Group(string&, string&);
		void addStudent(Student*);
		void chooseHead();
		Student* searchStudentName(string);
		Student* searchStudentId(int);
		double getAverageInGroup();
		void kickStudent(Student*);
		string getTitle();
		string getSpec();
		vector<Student*> getStudents();
		Student* getHead();
};