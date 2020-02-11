#include <string>
#include <vector>
#include "time.h"
#include "group.h"

Group::Group(string& title, string& spec){
	this->title = title;
	this->spec = spec;
}
void Group::addStudent(Student* student){
	students.push_back(student);
}
void Group::chooseHeadman(){
	headman = students[rand() % students.size()];
}
Student* Group::searchStudentById(int searchid) {
	for (auto student : students) 
		if (student->getId() == searchid) 
			return student;
		return nullptr;
}
Student* Group::searchStudentByName(string searchname) {
	for (auto student : students) 
		if (student->getName() == searchname) 
			return student;
		return nullptr;
}
double Group::getAverageValueInGroup(){
	if (students.size() == 0) 
		return;
	double average = 0.0;
	for (auto student : students) 
		average += student->getAverageValue();
	return average / students.size();
}
void Group::deleteStudent(Student* deleted){
	if (students.size() == 0) 
		return;
	int i = 0;
	for (auto student : students)
	{
		i++;
		if (student == deleted) 
			break;
	}
	students.erase(students.begin() + i - 1);
}
string Group::getTitle(){
	return title;
}
string Group::getSpec(){
	return spec;
}
vector<Student*> Group::getStudents(){
	return students;
}
Student* Group::getHeadman(){
	return headman;
}





