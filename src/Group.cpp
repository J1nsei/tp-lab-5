#include "Group.h" 
#include <vector>

Group::Group(string title_) {
	title = title_;
}
void Group::AddStudent(Student* Student_) {
	students.push_back(Student_);
}
Student* Group::ChosHead() {
	if (students.size() > 0) {
		if (students.size() > 1) {
			int number = rand() % students.size();
			head = students[number];
			return head;
		}
		else head = students[0];
		return head;
	}
	else return nullptr;
}
Student* Group::SearshStud(int id_) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->id == id_) {
			return students[i];
		}
	}
}
double Group::MediumMarkG() {
	double sum = 0;
	for (int i = 0; i < students.size(); i++) {
		sum = sum + students[i]->MedMark();
	}
	return sum / students.size();
}
void Group::DeleteStud(int id_) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->id == id_) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				ChosHead();
			}
			else{
				students.erase(students.begin() + i);
			}

		}
	}
}
int Group::GetSize() {
	return students.size();
}