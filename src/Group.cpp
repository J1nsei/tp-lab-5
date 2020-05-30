#include "Group.h" 
#include <vector>

Group::Group(string title_) {
	title = title_;
}
void Group::AddStudent(Student* Student_) {
	students.push_back(Student_);
}
Student* Group::ChoiceHead() {
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
Student* Group::SearchStudent(int id_) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->id == id_) {
			return students[i];
		}
	}
}
double Group::AveMarkGroup() {
	double sum = 0;
	for (int i = 0; i < students.size(); i++) {
		sum = sum + students[i]->AvMark();
	}
	return sum / students.size();
}
void Group::DeleteStud(int id_) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->id == id_) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				ChoiceHead();
			}
			else {
				students.erase(students.begin() + i);
			}

		}
	}
}
int Group::GetSize() {
	return students.size();
}