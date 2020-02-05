#include "Deanery.h"
#include <iostream>

Deanery::Deanery() {
}

int Deanery::getId() {
	static int id = 0;
	return ++id;
}

string extractName(string line) {
	return line.substr(0, line.find('|', 0));
}

string extractGroup(string line) {
	return line.substr(line.find('|', 0)+1, line.size());
}

int Deanery::createStudent(string group, string student) {
	Group* foundGroup = searchGroup(group);
	if (foundGroup != NULL) {
		return foundGroup->addStudent(new Student(getId(), student));
	}
	else {
		Group* newGroup = new Group(group);
		int exit_code = newGroup->addStudent(new Student(getId(), student));
		if (exit_code == 1) {
			groups.push_back(newGroup);
			return 1;
		}
		else {
			return -1;
		}
	}
	return -1;
}

Group* Deanery::searchGroup(string groupName) {
	for (int i = 0; i < groups.size(); i++) {
		if ((groups[i]->getTitle() == groupName)) {
			return groups[i];
		}
	}
	return NULL;
}

void Deanery::extractDataFromFile(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "NO FILE" << endl;
		return;
	}
	string line;
	int all = 0;
	int success = 0;
	while (getline(file, line)) {
		if (line == "") {
			continue;
		}
		all += 1;
		if (createStudent(extractGroup(line), extractName(line)) == 1) {
			success += 1;
		}
	}
	cout << all << "/" << success << "succesfful" << endl;
	file.close();
}


void Deanery::randMarks() {
	srand(time(NULL));
	for (int i = 0; i < groups.size(); i++)
	{
		for (int j = 0; j < groups[i]->students.size(); j++) {
			groups[i]->students[j]->addMark(rand() % 10 + 1);
		}
	}	
}

/*
void Deanery::changeGroup(string st, string newGr)
{
	int n = groups.size();
	int newGrNum = 0;
	for (int i = 0; i < n; i++) {
		if (groups[i]->getTitle() == newGr)
			newGrNum = i;
	}

	n = students.size();
	for (int i = 0; i < n; i++) {
		if (students[i]->getFio() == st) {
			(students[i]->getGroup())->eraseStudent(st);
			groups[newGrNum]->addStudent(students[i]);
			break;
		}
	}
}
*/

int Deanery::eraseWithBadMarks(double min_mark){
	if (min_mark < 0 || min_mark > 10) {
		return -1;
	}
	for (int i = 0; i < groups.size(); i++)
	{
		int hasErases = 1;
		if (hasErases) {
			hasErases = 0;
			for (int j = 0; j < groups[i]->students.size(); j++) {
				if (groups[i]->students[j]->getAvr() < min_mark && groups[i]->students[j]->marks.size() > 0) {
					groups[i]->eraseStudent(groups[i]->students[j]);
					hasErases = 1;
				}
			}
		}
	}
	return 0;
}


void Deanery::electionHead(){
	srand(time(NULL));
	int randomIndex;
	Student* newHead;
	for (int i = 0; i < groups.size(); i++) {
		randomIndex = rand() % groups[i]->students.size();
		newHead = groups[i]->students[randomIndex];
		groups[i]->setHead(newHead);
	}
}

void Deanery::getStatistics(){
	int n = groups.size();
	int t;
	for (int i = 0; i < n; i++) {
		cout <<"title: "<< groups[i]->getTitle() << endl;
		cout << "how many students: " << groups[i]->getNum() << endl;
		cout << "head: " << groups[i]->getHead()->getFio() << endl;
		for (int j = 0; j < groups[i]->getNum(); j++) {
			Student* student = groups[i]->students[j];
			cout << student->getId() << " ";
			for (auto &i: groups[i]->getMarks(student)) {
				cout << i << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
