#include "Dean.h"
#include <fstream>
#include<iostream>
#include <set>

Dean::Dean() {
	fileName = "";
	studentID = 0;
	system("chcp 1251");
	readFile();
	createGroups();
	createStudents();
}

Dean::Dean(std::string data_fileName) {
	fileName = data_fileName;
	studentID = 0;
	system("chcp 1251");
	readFile();
	createGroups();
	createStudents();
}

Dean::~Dean() {}

//read file and create data
void Dean::readFile() {
	std::ifstream file(fileName);
	//system("chcp 1251");
	std::string line;
	std::vector<std::string> resultSplit;
	//delete data, if it is
	if (!data.empty()) {
		data.clear();
	}
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line, '\n');
			if (line != ""){
				resultSplit = split(line, ';');
				data[resultSplit[0]] = resultSplit[1];
			}
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}


void Dean::updateData() {
	std::ofstream file(fileName);
	if (file.is_open()) {
		for (auto it = data.begin(); it != data.end(); it++) {
			file << it->first << ";" << it->second << '\n';
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void Dean::outputData() {
	std::ifstream file(fileName);
	//system("chcp 1251");
	std::string line;
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
}

std::vector<std::string> Dean::split(std::string str, char delimeter) {
	std::vector<std::string> result;
	std::string newStr = "";
	for (char i : str) {
		if (i == delimeter) {
			result.push_back(newStr);
			newStr = "";
		}
		else {
			newStr += i;
		}
	}
	result.push_back(newStr);
	return result;
}

void Dean::createStudents() {
	for (auto it = data.begin(); it != data.end(); it++, studentID++) {
		Student* student = new Student(studentID, it->first);
		//student joins to group
		for (Group* group : allGroups) {
			if (group->getName() == it->second) {
				student->setGroup(group);
				allStudents.push_back(student);
				group->addStudent(student);
				break;
			}
		}
	}
}

Student* Dean::findStudentById(unsigned int id) {
	for (Student* student : allStudents) {
		if (student->getID() == id) {
			return student;
		}
	}
	return 0;
}

void Dean::addMark(Student* student, int mark) {
	if (student != 0) {
		student->addMark(mark);
	}
}

double Dean::getStudentStatistics(Student* student) {
	if (student != 0) {
		return student->averageMark();
	}
	return -1.;
}

bool Dean::studentTransfer(Student* student, Group* to) {
	if (student != 0 && to != 0) {
		//expel student from currnet group
		expellStudentFromGroup(student);
		//change group
		student->setGroup(to);
		to->addStudent(student);
		//change data about students
		data[student->getFIO()] = to->getName();
		return true;
	}
	return false;
}

bool Dean::expelStudent(Student* student) {
	if (student != 0) {
		expellStudentFromGroup(student);
		deleteStudent(student);
		data.erase(student->getFIO());
		delete student;
		return true;
	}
	return false;
}


void Dean::addNewStudent(std::string name, Group* group) {	
	Student* student = new Student(studentID, name);
	studentID++;
	student->setGroup(group);
	group->addStudent(student);
	data[student->getFIO()] = group->getName();
	allStudents.push_back(student);	
}

bool Dean::deleteStudent(Student* findStudent) {
	for (auto iter = allStudents.begin(); iter != allStudents.end(); ++iter) {
		if ((*iter) == findStudent) {
			allStudents.erase(iter);
			return true;
			break;
		}
	}
	return false;
}


void Dean::expellStudentFromGroup(Student* student) {
	if (student != 0) {
		Group* groupFrom = student->getGroup();
		groupFrom->expelStudent(student);
	}
}

void Dean::createGroups() {
	//unique group names
	std::set<std::string> nameGroups;
	if (!data.empty()) {
		for (auto it = data.begin(); it != data.end(); it++) {
			nameGroups.insert(it->second);
		}
	}
	else {
		std::cout << "Data is not found" << std::endl;
	}
	if (!nameGroups.empty()) {
		for (std::string nameGroup : nameGroups) {
			Group* group = new Group(nameGroup);
			allGroups.push_back(group);
		}
	}
	else {
		std::cout << "Group names are not initialize" << std::endl;
	}
}

Group* Dean::findGroupByName(std::string groupName) {
	if (groupName == "") {
		std::cout << "Group name is not initialize" << std::endl;
	}
	else {
		for (Group* group : allGroups) {
			if (group->getName() == groupName) {
				return group;
			}
		}
	}
	return 0;
}

double Dean::getGroupStatistics(Group* group) {
	if (group == 0) {
		return -1.;
	}
	else{
		return group->averageMark();
	}	
}
