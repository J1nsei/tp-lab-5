#include <string>
#include <vector>
#include "student.h" /* не забыть переименовать */

class Group;

Student::Student(string fio, int id) {
	this->fio = fio;
	this->id = id;
}
void Student::addToGroup(Group* another){
	group = another;
}
void Student::addMark(int mark){
	marks.push_back(mark);
}
double Student::getAverageValue(){
	double sumofmarks = 0.0;
	if (marks.size==0) {
		return 0;
	}
	for (auto mark : marks) {
		sumofmarks += mark;
	}
	return sumofmarks / marks.size();
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