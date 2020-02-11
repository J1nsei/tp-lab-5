#include <string>
#include <vector>
#include "student.h"


class Group;

Student::Student(string name, int id){
	this->fio = name;
	this->id = id;
}

void Student::addToGroup(Group* new_group){
	group = new_group;
}

void Student::addMark(int mark){
	marks.push_back(mark);
}

double Student::getAverage(){
	double sum = 0.0;
	if (marks.size() == 0){
		return 0;
	}
	for (auto mark : marks){
		sum += mark;
	}
	return sum / marks.size();
}

string Student::getName(){
	return fio;
}

int Student::getId(){
	return id;
}

Group* Student::getGroup(){
	return group;
}

vector<int> Student::getMarks(){
	return marks;
}