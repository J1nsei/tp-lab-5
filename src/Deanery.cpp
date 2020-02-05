#include "Deanery.h"
#include <fstream>
#include <iostream>

void Deanery::CreateGroups(string fn) {
	string title, spec;
	ifstream in(fn);
	Group* group;
	if (in.is_open()){
		while (getline(in, title) && getline(in, spec)){
			group = new Group(title, spec);
			CreateStudents(title.append(".txt"), group);
			groups.push_back(group);
		}
	}
	in.close();
}
void Deanery::CreateStudents(string fn, Group* group){
	string fio;
	ifstream in(fn);
	if (in.is_open()) {
		while (getline(in, fio)) {
			group->AddStudent(fio);
		}
	}
	in.close();
}
void Deanery::AddRandMarks(int num){
	for (int i = 0; i < groups.size(); i++){
		(*groups[i]).AddRandMarks(num);
	}
}
void Deanery::PrintStat(){
	for (int i = 0; i < groups.size(); i++){
		(*groups[i]).PrintStat();
	}
}
void Deanery::Transf(string fio, string title1, string title2) {
	int i = 0, size = groups.size();
	while (i < size) {
		if (title1 == groups[i]->GetTitle()) {
			break;
		}
		i++;
	}
	Student* student = groups[i]->FindStudent(fio);
	groups[i]->ExpelStudent(fio);
	i = 0;
	while (i < size) {
		if (title2 == groups[i]->GetTitle()) {
			break;
		}
		i++;
	}
	groups[i]->AddStudent(student);
}
void Deanery::Expulsion(double points) {
	for (int i = 0; i < groups.size(); i++) {
		(*groups[i]).Expulsion(points);
	}
}
void Deanery::SaveData() {
	for (int i = 0; i < groups.size(); i++) {
		groups[i]->SaveData();
	}
}
void Deanery::ChooseHead() {
	for (int i = 0; i < groups.size(); i++) {
		(*groups[i]).ChooseHead();
	}
}
void Deanery::PrintData() {
	for (int i = 0; i < groups.size(); i++) {
		(*groups[i]).PrintInfo();
		cout << endl;
	}
}