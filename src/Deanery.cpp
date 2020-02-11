#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h> 
#include <time.h> 
#include "Deanery.h"
using namespace std;

Deanery::Deanery(string studentsFile, string specsFile) {
	this->studentsFile = studentsFile;
	this->specsFile = specsFile;
	createGroups();
	createStudents();
}

vector<string> Deanery::split(string& line) {
	vector<string> output(2);
	int dev_count = 0;
	for (int i = 0; i < size(line); i++) {
		if (line[i] == '|') {
			dev_count++;
			continue;
		}
		else {
			output[dev_count] += line[i];
		}
		if (line[i] == '/n') {
			break;
		}
	}
	return output;
}

Group* Deanery::createGroup(string title, string spec) {
	Group* new_group_p = new Group(title, spec);
	groups_p.push_back(new_group_p);
	return new_group_p;
}

void Deanery::createGroups() {
	ifstream finSpecs;
	finSpecs.open(specsFile);
	if (finSpecs.is_open()) {
		string line;
		vector<string> data(2);
		Group* group_p;
		while (getline(finSpecs, line)) {			
			data = split(line);
			group_p = createGroup(data[0], data[1]);		
		}
	}	
	else {
		cout << "Error" << endl;
	}
	finSpecs.close();
}

Student* Deanery::createStudent(int id, string fio){
	Student* new_student_p = new Student(id, fio);
	all_students_p.push_back(new_student_p);
	return new_student_p;
}

void Deanery::createStudents() {
	ifstream finStud;
	finStud.open(studentsFile);
	if (finStud.is_open()) {
		string line;
		vector<string> data(2);
		int dev_count = 0;
		int id = 0;
		Student* new_student_p;
		Group* students_group_p;

		while (getline(finStud, line)) {			
			data = split(line);
			new_student_p = createStudent(id, data[0]);
			students_group_p = searchGroup(data[1]);
			students_group_p->addStudent(new_student_p);
			//all_students_p.push_back(new_student_p);
			id++;
		}
	}
	else {
		cout << "Error" << endl;
	}
	finStud.close();	   	 
}

Group* Deanery::searchGroup(string group_title) {	
	for (int i = 0; i < groups_p.size(); i++) {
		if (group_title == groups_p[i]->title) {
			return groups_p[i];
		}
	}
	cout << "No such group!" << endl;
	return NULL;
}

Student* Deanery::searchStudentGeneral(int id) {
	Student* student;
	for (int i = 0; i < all_students_p.size(); i++) {
		if (all_students_p[i]->id == id) {
			student = all_students_p[i];
			return student;
		}
	}
	cout << "No such student!" << endl;
	return NULL;
}

Student* Deanery::searchStudentGeneral(string fio) {
	Student* student;
	for (int i = 0; i < all_students_p.size(); i++) {
		if (all_students_p[i]->fio == fio) {
			student = all_students_p[i];
			return student;
		}
	}
	cout << "No such student!" << endl;
	return NULL;
}

void Deanery::addMarksAll(int amount) {
	int mark;
	srand(time(NULL));
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < all_students_p.size(); j++) {
			mark = rand() % 11;
			all_students_p[j]->addMark(mark);
		}
	}
}

void Deanery::changeGroup(string fio, string new_group) {
	Student* student = searchStudentGeneral(fio);
	Group* previousGroup = student->group_p;
	previousGroup->removeStudent(fio);
	Group* new_group_p = searchGroup(new_group); 
	student->setGroup(new_group_p);
	new_group_p->addStudent(student);
	cout << "Student " << student->fio << " has been moved from " << previousGroup->title << " to " << new_group_p->title << endl;
}

void Deanery::removeStudentsForPoorMarks(int min_mark) {
	for (int i = 0; i < all_students_p.size(); i++) {
		if (all_students_p[i]->averageMark() < min_mark - 0.5) {
			Group* students_group = all_students_p[i]->group_p;
			students_group->removeStudent(all_students_p[i]->fio);
			removed_p.push_back(all_students_p[i]);
			cout << all_students_p[i]->fio << " has been removed from the Group for poor marks (the average mark is " << all_students_p[i]->averageMark() << ")" << endl;
		}
	}
}

void Deanery::headElectionAll() {
	int rand_ind;
	srand(time(NULL));
	for (int i = 0; i < groups_p.size(); i++) {
		rand_ind = rand() % groups_p[i]->students_p.size();
		groups_p[i]->chooseHead(groups_p[i]->students_p[rand_ind]);
		cout << groups_p[i]->students_p[rand_ind]->fio << " Has been chosen as the head of the group " << groups_p[i]->title << endl;
	}
}

void Deanery::studentInfo(string fio) {
	for (int i = 0; i < all_students_p.size(); i++) {
		if (all_students_p[i]->fio == fio) {
			cout << endl << "----------Student info----------" << endl;
			cout << "id: " << all_students_p[i]->id << "; Full name: " << all_students_p[i]->fio << endl << all_students_p[i]->group_p->title << " (" << all_students_p[i]->group_p->spec << ")" << endl;
			cout << "Marks:" << endl;
			for (int j = 0; j < all_students_p[i]->marks.size(); j++) {
				cout << all_students_p[i]->marks[j] << " ";
			}
			cout << endl <<  "The average mark is " << all_students_p[i]->averageMark();
			cout << endl << "--------------------------------" << endl;
			return;
		}
		else if (i == all_students_p.size() - 1 && all_students_p[i]->fio != fio) {
			cout << "No such student!" << endl;
		}
	}
}

void Deanery::groupInfo(string title) {
	Group* group_p = searchGroup(title);
	cout << endl << "-----------Group info-----------";
	cout << endl << group_p->title << " (" << group_p->spec << ")" << endl;
	cout << "Total amount of students: " << group_p->students_p.size() << endl;
	cout << "Average mark in the group: " << group_p->averageMarkGroup() << endl;
	cout << "The head of the group is: " << group_p->head->fio << endl;
	cout << "Student list: " << endl;
	for (int i = 0; i < group_p->students_p.size(); i++) {
		cout<< group_p->students_p[i]->id << " " << group_p->students_p[i]->fio << ". Marks: ";
		for (int j = 0; j < group_p->students_p[i]->marks.size(); j++) {
			cout << group_p->students_p[i]->marks[j] << " ";
		}
		cout << "(Average: " << group_p->students_p[i]->averageMark() << ")" << endl;
	}
	cout << "--------------------------------" << endl;
}

void Deanery::saveToFile(string outName) {
	ofstream fout;
	fout.open(outName);
	if (fout.is_open()) {
		for (int i = 0; i < all_students_p.size(); i++) {
			fout << all_students_p[i]->id << "|" << all_students_p[i]->fio << "|" << all_students_p[i]->group_p->title << "|";
			for (int j = 0; j < all_students_p[i]->marks.size(); j++) {
				fout << all_students_p[i]->marks[j] << " ";
			}
			fout << "|";
			for (int j = 0; j < removed_p.size(); j++) {
				if (all_students_p[i] == removed_p[j]) {
					fout << " *KICKED*";
				}
			}
			fout << endl;
		}

	}
	else {
		cout << "Error" << endl;
	}	
}