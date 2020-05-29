#include <string>
#include <vector>
#include "Student.h"

class Group;
Student::Student(std::string name, std::string id) {
	this->fullName = name;
	this->id = id;
}
double Student::calculateAverage() const {
	double sum = 0.0;
	if (marks.size() == 0) {
		return 0;
	}
	for (auto & mark : marks) {
		sum += mark;
	}
	return sum / marks.size();
}
void Student::addToGroup(Group* newGroup) {
	group = newGroup;
}
std::string Student::getName() const {
	return fullName;
}
std::string Student::getId() const {
	return id;
}
Group* Student::getGroup() const {
	return group;
}
std::vector<int> Student::getMarks() const {
	return marks;
}

void Student::addMark(int mark) {
	marks.push_back(mark);
}