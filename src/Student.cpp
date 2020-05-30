#include "Student.h"
#include <iostream>
using namespace std;


#include <vector>

Student::Student(int id_, string fio_) {
	id = id_;
	fio = fio_;
}
void Student::AddToGroup(string group_) {
	group = group_;
}
void Student::AddMark() {
	marks.push_back(rand() % 11);
}
double Student::AvMark() {
	double sum = 0;
	for (int i = 0; i < marks.size(); i++) {
		sum = sum + marks[i];
	}
	double a = sum / marks.size();
	return a;
}
int Student::MarkSize() {
	return marks.size();
}
string Student::GetFio() {
	return fio;
}
int Student::GetId() {
	return id;
}