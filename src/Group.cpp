

#include "Group.h"
using namespace std;


Group::Group(string name1) {
	title = name1;
	size = 0;
}

void Group::add_Student(const string& student_name) {
	Student student(students.size()+1, student_name, this->title);
	students.push_back(student);
	size++;
}

void Group::add_head(int id) {
	head = students[id];
}


Student* Group::search_Student(const  int id) { 
	if (id >= 0 && id < students.size())
		return &students[id];
	else
		return nullptr;
}

Student* Group::search_Student(const string& student_name) {
	for (auto& student : students) {
		if (student_name == student.get_name()) {
			return &student;
		}
	}
	return nullptr;
}

double Group::group_average_mark()
{
	double sum = 0;
	for (size_t i = 0; i < students.size(); i++) {
		sum += students[i].average_Mark();
	}
	return(sum / students.size());
}

void Group::Delete_students(const int id)
{
	string group;
	for (size_t i = 0; i < students.size(); i++) {
		if (students[i].get_id()-1 == id) {
			if (students[i].get_name() == get_head().get_name()) {
				students.erase(students.begin() + i);
				size--;
				this->add_head(rand() % size);
			}
			else {
				students.erase(students.begin() + i);
				size--;
			}
		}
	}
}

void Group::Delete_students(const string student_name) {
	int id = search_Student(student_name)->get_id();
	for (size_t i = 0; i < students.size(); i++) {
		if (students[i].get_id() - 1 == id) {
			if (students[i].get_name() == get_head().get_name()){
				students.erase(students.begin() + i);
				size--;
				this->add_head(rand() % size);
			}
			else {
				students.erase(students.begin() + i);
				size--;
			}
		}
	}
}

size_t Group::get_size() const { return size; }
 
Student Group::get_head(){
	return head; 
}

string Group::get_title()
{
	return title;
}



