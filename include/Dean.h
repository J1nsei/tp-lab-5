#pragma once
#include "Group.h"
#include "Student.h"
#include <vector>
#include <string>
#include <map>


class Student;
class Group;

class Dean
{	
	std::string fileName;
	std::map<std::string, std::string> data;
	std::vector<std::string> split(std::string str, char delimeter);
	void readFile();

	unsigned int studentID;
	std::vector<Student*> allStudents;
	bool deleteStudent(Student* findStudent);

	std::vector<Group*> allGroups;
	void expellStudentFromGroup(Student* student);

public:
	Dean();
	Dean(std::string fileName);
	~Dean();
	//with students
	void createStudents();
	void addMark(Student* student, int mark);
	Student* findStudentById(unsigned int id);
	double getStudentStatistics(Student* student);
	bool studentTransfer(Student* student, Group* to);
	bool expelStudent(Student* student);
	void addNewStudent(std::string name, Group* group);

	//with groups
	void createGroups();	
	Group* findGroupByName(std::string groupName);	
	double getGroupStatistics(Group* group);

	//with data
	void updateData();
	void outputData();
};

