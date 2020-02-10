#include "Deanery.h"
#include <iostream>

Deanery::Deanery() {
	this->id = 0;
}

int Deanery::getid() {
	id += 1;
	return id;
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
		return foundGroup->addStudent(new Student(getid(), student));
	}
	else {
		Group* newGroup = new Group(group);
		int exit_code = newGroup->addStudent(new Student(getid(), student));
		if (exit_code == 0) {
			groups.push_back(newGroup);
			return 0;
		}
		else {
			return -1;
		}
	}
	return 0;
}

Group* Deanery::searchGroup(string groupName) {
	for (int i = 0; i < groups.size(); i++) {
		if ((groups[i]->getTitle() == groupName)) {
			return groups[i];
		}
	}
	return NULL;
}

int Deanery::extractDataFromFile(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "NO FILE" << endl;
		return -1;
	}
	string line;
	int all = 0;
	int success = 0;
	while (getline(file, line)) {
		if (line == "") {
			continue;
		}
		all += 1;
		if (createStudent(extractGroup(line), extractName(line)) == 0) {
			success += 1;
		}
	}
	cout << success << "/" << all << "succesfful" << endl;
	file.close();
	return 0;
}

vector<Student*> Deanery::searchStudent(string fio) {
	vector<Student*> foundStudents;
	for (auto &group : groups) {
		for (auto &student: group->students) {
			if ((student->getFio() == fio)) {
				foundStudents.push_back(student);
			}
		}
	}
	return foundStudents;
}

Student* Deanery::searchStudent(int id) {
	for (auto& group : groups) {
		for (auto& student : group->students) {
			if ((student->getId() == id)) {
				return student;
			}
		}
	}
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
	cout << "STATISTIC:" << endl << endl;
	for (int i = 0; i < n; i++) {
		cout <<"title: "<< groups[i]->getTitle() << endl;
		cout << "how many students: " << groups[i]->getNum() << endl;
		cout << "head: " << groups[i]->getHead()->getFio() << endl;
		for (int j = 0; j < groups[i]->getNum(); j++) {
			Student* student = groups[i]->students[j];
			cout << "student id: " << student->getId() << " " << "FIO: " << student->getFio() << " marks: ";
			for (auto &mark: groups[i]->getMarks(student)) {
				cout << mark << " " << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
}

int Deanery::saveDataInFile(string filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "NO FILE" << endl;
		return -1;
	}
	string line;
	int all = 0;
	int success = 0;
	for (auto &group : groups) {
		for (auto& student : group->students) {
			file << student->getFio() << "|" << group->getTitle() << endl;
		}
	}
	file.close();
	return 0;
}

int Deanery::changeGroup(Student* student, Group* group) {
	if (student == NULL || group == NULL) {
		return -1;
	}
	if (student->getGroup() == group) {
		return 0;
	}
	if (group->searchStudent(student->getId()) != NULL) {
		return -1; // if a group gets already this student 
	}
	student->getGroup()->eraseStudent(student);
	group->addStudent(student);
	return 0;

}