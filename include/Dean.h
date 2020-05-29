#ifndef DEAN_H
#define DEAN_H
#include "Student.h"
#include "Group.h"
class Group;
class Student;

class Dean {
private:
	std::string name;
	std::vector<Group> groups;
	int currentCounterID;
public:
	Dean(const std::string& name);
	Group* createGroup(const std::string&, const std::string&);
	void addStudentToGroup(const std::string& studentName, const std::string &);
	Group* trasferStudentToNewGroup(const std::string& studentName, const std::string& currentGroup, const std::string& newGroup);
	int expelStudentsByAverageMark(double mark);
	void addMarkToStudent(const std::string&, const std::string& , int);
	Group* searchGroupByName(std::string groupName);
	friend  std::ostream& operator<<( std::ostream& out, const Dean& obj);
	std::string chooseMonitorInGroup(const std::string&);
	void updateData(const std::string&);
	double getAverageMarkInGroup(const std::string&);
	double getAverageMarkOfStudent(const std::string&, const std::string&);
	int getNumberOfStudentsInGroup(const std::string& groupName);
};
#endif