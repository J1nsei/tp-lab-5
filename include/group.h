#pragma once;
#include <string>
#include <vector>
#include "student.h" /* dont forget change name */ 

class Group {
	private:
	string title;
	string spec;
	vector<Student*>students;
	Student* headman;
	public:
	Group (string&, string&);
	void addStudent(Student*);
	void chooseHeadman();
	Student* searchStudentById(int);
	Student* searchStudentByName(string);
	double getAverageValueInGroup();
	void deleteStudent(Student*);
	string getTitle();
	string getSpec();
	vector<Student*> getStudents();
	Student* getHeadman();
}