#include "Group.h"
#include <random>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

Group::Group(string title, string spec) {
	this->title = title;
	this->spec = spec;
}
void Group::AddStudent(string fio) {
	this->students.push_back(new Student(this->students.size(), fio, this));
}
void Group::AddStudent(Student* student) {
	student->SetGroup(this);
	student->SetId(students.size());
	this->students.push_back(student);
}
void Group::ChooseHead() {
	srand(time(0));
	int num = rand() % this->students.size();
	this->head = this->students[num];
}
double Group::CalcAverage() {
	double sum = 0, num = 0;
	int buf1, buf2;
	for (int i = 0; i < this->students.size(); i++) {
		(*students[i]).GetSumNum(&buf1, &buf2);
		sum += buf1;
		num += buf2;
	}
	if (num != 0) {
		return sum / num;
	}
	else {
		return -1;
	}
}
void Group::AddRandMarks(int num) {
	for (int i = 0; i < students.size(); i++) {
		for (int j = 0; j < num; j++) {
			(*students[i]).AddMark(rand() % 11);
		}
	}
}
void Group::PrintStat() {
	cout << "Средний балл в группе " << this->title << ": "  << this->CalcAverage() << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << (*students[i]).GetId() << " " << (*students[i]).GetFio() << ": " << (*students[i]).CountAverage() << endl;
	}
	cout << endl;
}
void Group::ExpelStudent(string fio) {
	int i = 0, size = students.size();
	bool flag = false;
	while (i < size) {
		if (fio == (*students[i]).GetFio()) {
			break;
		}
		i++;
	}
	if (head == students[i]) {
		flag = true;
	}
	students.erase(students.begin() + i);
	size = students.size();
	while (i < size) {
		(*students[i]).DecId();
		i++;
	}
	if (flag) {
		this->ChooseHead();
	}
}
void Group::ExpelStudent(int id) {
	int size = students.size();
	bool flag = false;
	if (id < size) {
		if (head == students[id]) {
			flag = true;
		}
		students.erase(students.begin() + id);
		size = students.size();
		while (id < size) {
			(*students[id]).DecId();
			id++;
		}
		if (flag) {
			this->ChooseHead();
		}
	}
}
Student* Group::FindStudent(string fio) {
	for (int i = 0; i < students.size(); i++) {
		if (fio == (*students[i]).GetFio()) {
			return students[i];
		}
	}
	return NULL;
}
Student* Group::FindStudent(int id) {
	if (id < students.size()) {
		return students[id];
	}
	else {
		return NULL;
	}
}
string Group::GetTitle() {
	return title;
}
void Group::Expulsion(double points) {
	int i = 0;
	while (i < students.size()) {
		if (students[i]->CountAverage() < points) {
			this->ExpelStudent(i);
			i--;
		}
		i++;
	}
}
void Group::SaveData() {
	ofstream fout(title + "1.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	int size = students.size();
	for (int i = 0; i < size; i++) {
		fout << students[i]->GetFio() << endl; // запись строки в файл
	}
	fout.close();
}
void Group::PrintInfo() {
	cout << "Title: " << title << endl
		<< "Specification: " << spec << endl
		<< "Head: " << head->GetFio() << endl
		<< "Students: " << endl;
	for (int i = 0; i < students.size(); i++) {
		students[i]->PrintInfo();
	}
}
