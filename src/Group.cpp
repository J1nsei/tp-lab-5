#include <string>
#include <vector>
#include <time.h>
#include "Student.h"
#include "Group.h"

Group::Group(const std::string & name, const std::string & specialization) {
	this->name = name;
	this->specialization = specialization;
}

std::string Group::getGroupName() const {
	return name;
}

Student* Group::chooseMonitor() {
	srand(time(NULL));
	int groupSize = listOfStudents.size();
	monitor = &listOfStudents[rand() % groupSize];
	return monitor;
}
Student* Group::searchStudentByName(std::string name) {
	for (auto & student : listOfStudents) {
		if (student.getName() == name) {
			return &student;
		}
	}
	return nullptr;
}
Student* Group::searchStudentById(std::string id) {
	for (auto & student : listOfStudents) {
		if (student.getId() == id) {
			return &student;
		}
	}
	return nullptr;
}
void Group::addStudent(Student student) {
	listOfStudents.push_back(student);
	listOfStudents[listOfStudents.size() - 1].addToGroup(this);
}
void Group::expelStudent(Student student) {
	if (listOfStudents.size() == 0)
		return;
	int i = 0;
	for (i = 0; i < listOfStudents.size(); i++) {
		if (listOfStudents[i].getId() == student.getId()) {
			break;
		}
	}
	if (listOfStudents.size() == i)
		return;
	listOfStudents.erase(listOfStudents.begin()+i);
}
double Group::calculateAverageMarkInGroup(){
	if (listOfStudents.size() == 0) {
		return 0;
	}
	double average = 0;
	for (auto & student : listOfStudents) {
		average += student.calculateAverage();
	}
	return average / listOfStudents.size();
}