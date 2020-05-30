#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Group.h"
std::vector<std::string> split(std::string& line);

class Deanery {
private:	
	std::string studentsFile;
	std::string specsFile;
	std::vector<Group*> groups_p;
	std::vector<Student*> all_students_p;
	std::vector<Student*> removed_p;

	std::vector<std::string> split(std::string& line);
	void createGroups();
	void createStudents();
public:
	Deanery(std::string studentsFile, std::string specsFile);
	Group* createGroup(std::string title, std::string spec);
	Student* createStudent(int id, std::string fio);
	Group* searchGroup(std::string group_title);	
	Student* searchStudentGeneral(int id);
	Student* searchStudentGeneral(std::string fio);
	void addMarksAll(int amount);
	void changeGroup(std::string student, std::string new_group);
	void removeStudentsForPoorMarks(int min_mark);
	void headElectionAll();
	void studentInfo(std::string fio);
	void groupInfo(std::string);
	void saveToFile(std::string);
};