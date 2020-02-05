#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(int id, string fio, Group* group) {
	this->fio = fio;
	this->id = id;
	this->group = group;
}
void Student::SetGroup(Group *group) {
	this->group = group;
}
void Student::AddMark(int mark) {
	this->marks.push_back(mark);
}
double Student::CountAverage() {
	double num = 0, len = this->marks.size();
	for (int i = 0; i < len; i++) {
		num += marks[i];
	}
	if (len != 0) {
		return num / len;
	}
	else {
		return -1;
	}
}
void Student::GetSumNum(int* sum, int* num) {
	int sumD = 0, numD = this->marks.size();
	for (int i = 0; i < numD; i++) {
		sumD += marks[i];
	}
	*sum = sumD;
	*num = numD;
}
string Student::GetFio(){
	return fio;
}
int Student::GetId() {
	return id;
}
void Student::DecId() {
	id--;
}
void Student::SetId(int id) {
	this->id = id;
}
void Student::PrintInfo() {
	cout << id << " " << fio << " ";
	for (int i = 0; i < marks.size(); i++) {
		cout << marks[i] << " ";
	}
	cout << endl;
}
