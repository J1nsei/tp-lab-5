#include <fstream>
#include <iostream>
#include <sstream>
#include "dean.h"


void Deanery::createStudent(int stud_id, string stud_name, Group* gr){
	Student* stud = new Student(stud_name, stud_id);
	gr->addStudent(stud);
}

Group* Deanery::createGroup(string name, string specialization){
	Group* gr = new Group(name, specialization);
	groups.push_back(gr);
	return gr;
}

void Deanery::addMarks(Group* gr, string stud, int mark){
	Student* st = gr->searchStudentName(stud);
	st->addMark(mark);
}

double Deanery::getAverageStudent(Group* gr, string name){
	Student* stud = gr->searchStudentName(name);
	return stud->getAverage();
}

double Deanery::getAverageGroup(Group* gr){
	return gr->getAverageInGroup();
}

void Deanery::changeGroup(string name, Group* old_group, Group* new_group){
	Student* stud = old_group->searchStudentName(name);
	old_group->kickStudent(stud);
	stud->addToGroup(new_group);
	new_group->addStudent(stud);
}

void Deanery::kickForMarks(Group* gr){
	for (auto stud : gr->getStudents())
	if (stud->getAverage() < 4.0)
		gr->kickStudent(stud);
}

void Deanery::saveData(){
	ofstream file("dean.txt");
	for (auto group : groups){
		file << "Название: " << group->getTitle() << endl;
		file << "Специальность: " << group->getSpec() << endl;
		file << "Староста: " << group->getHead()->getName() << endl;
		file << "Студенты: " << endl;
		for (auto student : group->getStudents()){
			file << "Имя: " << student->getName() << endl;
			file << "Номер: " << student->getId() << endl;
			file << "Средний балл: " << student->getAverage() << endl;
			file << "Оценки: ";
			for (auto mark : student->getMarks())
				file << mark << " ";
			file << endl;
		}
	}
}

void Deanery::initializeHead(Group* gr){
	gr->chooseHead();
}

void Deanery::printData(){
	for (auto group : groups){
		cout << "Название: " << group->getTitle() << endl;
		cout << "Специальность: " << group->getSpec() << endl;
		cout << "Староста: " << group->getHead()->getName() << endl;
		cout << "Студенты: " << endl;
		for (auto student : group->getStudents()){
			cout << "Имя: " << student->getName() << endl;
			cout << "Номер: " << student->getId() << endl;
			cout << "Средний балл: " << student->getAverage() << endl;
			cout << "Оценки: ";
			for (auto mark : student->getMarks())
				cout << mark << " ";
			cout << endl;
		}
	}
}