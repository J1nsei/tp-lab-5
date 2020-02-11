#include <fstream>
#include <iostream>
#include <sstream>
#include "deanery.h"

void Deanery::createStudent(int student_id, string student_name, Group* gr){
	Student* newstud = new Student(student_name,student_id);
	gr->addStudent(newstud);
}
Group* Deanery::createGroup(string name, string speciality){
	Group* gr = new Group(name,speciality);
	groups.push_back(gr);
	return gr;
}
void Deanery::addMarks(Group* gr, string stud, int mark){
	Student* st = gr->searchStudentByName(stud);
	st->addMark(mark);
}
double Deanery::getAverageStudent(Group* gr, string name){
	Student* stud = gr->searchStudentByName(name);
	return stud->getAverageValue();
}
double Deanery::getAverageGroup(Group* gr){
	return gr->getAverageValueInGroup();
}
void Deanery::changeGroup(string name, Group* previous, Group* present){
	Student* stud = previous->searchStudentByName(name);
	previous->deleteStudent(stud);
	stud->addToGroup(present);
	present->addStudent(stud);
}
void Deanery::deleteForMarks(Group* gr){
	for (auto student : gr->getStudents())
		if (student->getAverageValue() < 4.0) 
			gr->deleteStudent(student);
}
void Deanery::saveData(){
	ofstream file("deanery.txt");
	for (auto group : groups){
		file << "Название: " << group->getTitle() << endl;
		file << "Специальность: " << group->getSpec() << endl;
		file << "Староста: " << group->getHead()->getName() << endl;
		file << "Студенты: " << endl;
		for (auto student : group->getStudents()){
			file << "Имя: " << student->getName() << endl;
			file << "Номер: " << student->getId() << endl;
			file << "Средний балл: " << student->getAverageValue() << endl;
			file << "Оценки: ";
			for (auto mark : student->getMarks())
				file << mark << " ";
			file << endl;
		}
	}
}
void Deanery::initializeHeadmen(Group* gr){
	gr->chooseHeadman();
}
void Deanery::printData(){
	for (auto group : groups){
		cout << "Название: " << group->getTitle() << endl;
		cout << "Специальность: " << group->getSpec() << endl;
		cout << "Староста: " << group->getHeadman()->getName() << endl;
		cout << "Студенты: " << endl;
		for (auto student : group->getStudents()){
			cout << "Имя: " << student->getName() << endl;
			cout << "Номер: " << student->getId() << endl;
			cout << "Средний балл: " << student->getAverageValue() << endl;
			cout << "Оценки: ";
			for (auto mark : student->getMarks())
				cout << mark << " ";
			cout << endl;
		}
	}
}