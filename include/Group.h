#pragma once
#include <vector>
#include <string>
#include "Student.h"

class Group {
	friend class Deanery;
private:
	std::string title;
	std::string spec;
	std::vector<Student*> students_p;
	Student* head;
public:
	Group(std::string title, std::string spec);
	std::string getTitle();
	std::string getSpec();
	std::vector<Student*> getStudents_p();
	Student* getHead();
	void addStudent(Student* student);
	void chooseHead(Student* student);
	Student* searchStudent(int id);
	Student* searchStudent(std::string fio);
	double averageMarkGroup();
	void removeStudent(int id);
	void removeStudent(std::string fio);
};