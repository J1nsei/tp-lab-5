#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <vector>
#include <string>

class Student;
class Dean;

class Group {
private:
	std::string name;
	std::string specialization;
	std::vector<Student> listOfStudents;
	Student* monitor; //староста
	void addStudent(Student);
	void expelStudent(Student);
	Student* chooseMonitor();
public:
	Group(const std::string&, const std::string&);
	std::string getGroupName() const;
	Student* searchStudentByName(std::string);
	Student* searchStudentById(std::string);
	double calculateAverageMarkInGroup();
	friend Dean;
	friend  std::ostream& operator<<( std::ostream& out, const Dean& obj);
};

#endif