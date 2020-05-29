#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include "Dean.h"

Dean::Dean(const std::string& name) {
	this->name = name;
}
Group* Dean::createGroup(const std::string& groupName, const std::string& specialization) {
	groups.push_back(Group{ groupName, specialization });
	return &groups[groups.size() - 1];
}
void Dean::addStudentToGroup(const std::string& studentName, const std::string& groupName) {
	currentCounterID++;
	Group* group = searchGroupByName(groupName);
	Student student{ studentName,std::to_string(currentCounterID) };
	group->addStudent(student);
}
Group* Dean::trasferStudentToNewGroup(const std::string& studentName, const std::string& currentGroupName, const std::string& newGroupName) {
	Group* newGroup = searchGroupByName(newGroupName);
	Group* currentGroup = searchGroupByName(currentGroupName);
	Student* student = currentGroup->searchStudentByName(studentName);
	if (student) {
		newGroup->addStudent(*student);
		currentGroup->expelStudent(*student);
	};
	return newGroup;
}
int Dean::expelStudentsByAverageMark(double mark) {
	int expelCounter = 0;
	for (auto & group: groups) {
		for (int i = 0; i < group.listOfStudents.size(); i++) {
			if (group.listOfStudents[i].calculateAverage() < mark) {
				group.expelStudent(group.listOfStudents[i]);
				i--;
				expelCounter++;
			}
		}
	}
	return expelCounter;
}
Group* Dean::searchGroupByName(std::string groupName) {
	for (auto & group : groups) {
		if (group.name == groupName)
			return &group;
	}
	return nullptr;
}

 std::ostream& operator<<(std::ostream& out, const Dean& obj) {
	out << std::string("Название факультета: ") << obj.name << std::string("\n");
	for (auto group : obj.groups) {
		out << std::string("-- Название группы и специализация: ") << group.name << "(" << group.specialization << ")";
		if (group.monitor != NULL) {
			out << ", староста: " << group.monitor->getName();
		}
		out << std::endl;
		out << "-- Количество человек в группе: " << group.listOfStudents.size() << std::endl;
		out << "-- Средний балл в группе: " << group.calculateAverageMarkInGroup() << std::endl;
		for (auto& student : group.listOfStudents) {
			out << std::string("---- Студент: ") << student.getName() << std::string(", средняя оценка: ") << student.calculateAverage() << ", id: " << student.getId() << "\n";
		}
	}
	return out;
}

 void Dean::addMarkToStudent(const std::string& name, const std::string& groupName, int mark) {
	 Group* group = searchGroupByName(groupName);
	 Student* student = group->searchStudentByName(name);
	 student->addMark(mark);
}

std::string Dean::chooseMonitorInGroup(const std::string& groupName) {
	 Group* group = searchGroupByName(groupName);
	 group->chooseMonitor();
	 return group->monitor->getName();
 }

 void Dean::updateData(const std::string& file) {
	 std::fstream fout(file);
	 for (auto& group : groups) {
		 for (auto& student : group.listOfStudents) {
			 fout << student.getName() << ":" << group.getGroupName() << std::endl;
		 }
	 }
 }

 double Dean::getAverageMarkInGroup(const std::string& name) {
	 return searchGroupByName(name)->calculateAverageMarkInGroup();
 }
 double Dean::getAverageMarkOfStudent(const std::string& name, const std::string& groupName) {
	 Group* group = searchGroupByName(groupName);
	 Student* student = group->searchStudentByName(name);
	 return student->calculateAverage();
 }

 int Dean::getNumberOfStudentsInGroup(const std::string& groupName){
	 return searchGroupByName(groupName)->listOfStudents.size();
 }