#pragma once
#include "Student.h"

class Group {
private:
	string name;
	string spec;
	Student* head; 
	vector<Student*> students;
public:
	Group(string name, string spec);
	void addStudent(Student*);
	void removeStudent(Student*); 
	Student* findStudent(string fio); 
	Student* findStudent(int id);
	Student* chooseHead();
	double averageGroupMark();
	string getGroupName() const;
	string getGroupSpec() const;
	Student* getGroupHead() const;
	vector<Student*> getGroupStudents() const;
	friend Student;
};
