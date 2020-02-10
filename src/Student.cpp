#include "Student.h"

#include <vector>

Student::Student(int id_, string fio_) {
	id = id_;
	fio = fio_;
}
void Student::AddInGroup(string group_) {
	group = group_;
}
void Student::AddMark() {
	marks.push_back(rand()%6);
}
double Student::MedMark() {
	double sum = 0;
	for (int i = 0; i < marks.size(); i++) {
		sum = sum + marks[i];
	}
	return sum / marks.size();
}
int Student::MarkSize() {
	return marks.size();
}