#include <string>
#include <vector>
#include <time.h>
#include "group.h"


Group::Group(string& name, string& spec){
	this->title = name;
	this->spec = spec;
}

void Group::addStudent(Student* student){
	students.push_back(student);
}

void Group::chooseHead(){
	head = students[rand() % students.size()];
}

Student* Group::searchStudentName(string searched_name){
	for(auto student : students)
		if(student->getName() == searched_name)
			return student;
	return nullptr;
}

Student* Group::searchStudentId(int searched_id){
	for(auto student : students)
		if(student->getId() == searched_id)
			return student;
	return nullptr;
}

double Group::getAverageInGroup(){
	if(students.size() == 0)
		return 0;
	double aver = 0.0;
	for(auto student : students)
		aver += student->getAverage();
	return aver / students.size();
}

void Group::kickStudent(Student* kicked){
	if (students.size() == 0)
		return;
	int i = 0;
	for (auto student : students)
	{
		i++;
		if (student == kicked)
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

Student* Group::getHead(){
	return head;
}
