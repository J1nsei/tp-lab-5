#include "dean.h"
#include "group.h"
#include <vector>
#include <string>
using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

Dean::Dean()
{
	/* Создаём группы */
	ifstream file_of_groups("groups.txt");
	system("chcp 1251");
	while (!file_of_groups.eof()) {
		string buf;
		getline(file_of_groups, buf, '\n');
		Group new_group(buf);
		groups.push_back(new_group);
	}

	/* Распределяем студентов по группам
	Считываем список студентов и отправляем по группам */ 
	ifstream file_of_students("students.txt");
	system("chcp 1251");
	while (!file_of_students.eof()) {
		string buf;
		getline(file_of_students, buf, '\n');
		vector<string> data = split(buf, ':');
		Student new_student(data[0], data[1]);
		for (int i = 0; i < groups.size(); i++) {
			string name_of_group = groups[i].getName();
			if (name_of_group == data[1]) {
				groups[i].addStudent(new_student);
				break;
			}
		}
	}
};

void Dean::setMarks() {
	for (int i = 0; i < groups.size(); i++) {
		groups[i].setMarks();
	}
}

Group* Dean::findGroup(const string group_name) {
	for (auto &group : groups) {
		if (group.getName() == group_name)
			return &group;
	}
	return nullptr;
}

void Dean::setHeads() {
	for (auto& group : groups)
		group.setHead();
}

void Dean::allocation() {
	for (auto& group : groups)
		group.allocation();
}

void Dean::transfer(string from, string where) {
	if (from == where) {
		cout << "Ошибка при переводе студентов!" << endl;
		return;
	}
	Student transferred_student;
	for (auto& group : groups) {
		if (group.getName() == from) {
			transferred_student = group.transferFrom();
			break;
		}
	}
	for (auto& group : groups) {
		if (group.getName() == where) {
			group.addStudent(transferred_student);
			break;
		}
	}
}

void Dean::scholarship() {
	for (auto& group : groups)
		group.scholarship();
}

void Dean::statistics() {
	Group* best_group = nullptr;
	double best_mark = 0;
	cout << endl;
	for (auto& group : groups) {
		cout << "Средний балл группы " << group.getName() << " - " << group.averageMark() << endl;
		if (group.averageMark() > best_mark) {
			best_mark = group.averageMark();
			best_group = &group;
		}
	}
	cout << endl;
	cout << "Самые высокие показатели имеет группа " << best_group->getName() << "! Их средний балл по группе - " << best_group->averageMark() << endl << endl;
	cout << "Стипендию будут получать следующие студенты:" << endl;
	scholarship();
}

void Dean::savingData() {
	ofstream fout;
	fout.open("output.txt");
	vector<Student> allStudents;
	for (auto& group : groups) {
		allStudents = group.getStudents();
		for (auto& student : allStudents)
			fout << student.getName() << ":" << group.getName() << endl;
	}
	fout.close();
}

unsigned int Dean::getStudents() {
	unsigned int studentCounter = 0;
	for (auto& group : groups) {
		studentCounter += group.getStudents().size();
	}
	return studentCounter;
}

unsigned int Dean::getGroups() {
	return groups.size();
}