#include <iostream>
#include "Group.h"
#include <string>
#include <vector>

using namespace std;

void Group::addStudent(std::string fullName) {
	if (students.size() == 0) {
		groupID = 0;
	}
	else {
		groupID = getLastStudentId() + 1;
	}
	
	students.push_back(new Student(groupID, fullName/*, getLink()*/));
	(*(students[students.size() - 1])).addToGroup(this);
}

int Group::getLastStudentId() {
	//return (*(students[students.size() - 1])).getId();
	if (students.size() == 0) {
		return 0;
	}
	else {
		return (*(students[students.size() - 1])).getId();
	}
}

void Group::resizeStudentsVector() {
	students.resize(1);
}

Student* Group::headChoice() {
	double maxMark = 0;
	//Student* head;
	for (int i = 0; i < students.size(); i++) {
		/*if (*students[i].averageMark() > maxMark) {
			maxMark = students[i].averageMark();
			head = &students[i];
		}*/

		if ((students[i])->averageMark() > maxMark) {
			maxMark = students[i]->averageMark();
			head = students[i];
		}
	}

	return head;
}

double Group::averageGroupMark() {
	int counter = 0;
	double averageMarks = 0;
	for (int i = 0; i < students.size(); i++) {
		averageMarks += (*(students[i])).averageMark();
		counter++;
	}
	return averageMarks / counter;
}

 Student* Group::searchStudent(int id) {
	int vectorElementNum = 0;
	for (int i = 0; i < students.size(); i++) {
		vectorElementNum++;
		//cout << (*(students[i])).getId() << " " << id << endl;
		if ((*(students[i])).getId() == id) {
			return students[i];
		}
	}
	return nullptr;
}

Student* Group::searchStudent(std::string fio) {
	for (int i = 0; i < students.size(); i++) {
		if ((*(students[i])).getFIO() == fio) {
			return students[i];
		}
	}
}

//void Group::excludeStudent(int id) {
//	//int studentNum = (*(searchStudent(id))).getId();
//	students.erase(students.begin() + (*(searchStudent(id))).getId());
//}

Group* Group::getLink() {
	return this;
}

void Group::printTitle() {
	cout << title << endl;
}

void Group::printStudents() {
	for (int i = 0; i < students.size(); i++) {
		cout << i << ") " << students[i]->getFIO() << endl;
	}
}

Student* Group::dismissalStudent(int id) {
	// ищет студента по айди
	// erase его из группы по айди
	Student* _toDismiss = students[0];
	//_toDismiss = searchStudent(id);

	int _counter = 0;
	while (students[_counter]->getId() != id) {
		_counter++;
	}
	_toDismiss = students[_counter];
	_toDismiss->addToGroup(nullptr);
	students.erase(students.begin() + _counter);
	return _toDismiss;
}

void Group::addRandomMarks() {
	for (int i = 0; i < students.size(); i++) {
		students[i]->addMark(rand() % 9 + 1);
	}
}

void Group::recieveStudent(Student* reciever) {
	reciever->addToGroup(this);
	groupID = getLastStudentId() + 1;
	reciever->setId(groupID);
	students.push_back(reciever);
}

void Group::studentDismissalProgressless() {
	vector <int> ids;
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->averageMark() < 4.5) {
			ids.push_back(students[i]->getId());
		}
	}

	Student* _toDismiss;
	for (int i = 0; i < ids.size(); i++) {
		_toDismiss = dismissalStudent(ids[i]);
		delete(_toDismiss);
	}
}

string Group::getTitle() {
	return title;
}

void Group::statistics() {
	ofstream fout;
	fout.open("statistics/statistics.txt", ofstream::out | ios_base::app);

	fout << getTitle() << endl;
	for (int i = 0; i < students.size(); i++) {
		fout << i + 1 << ") " << students[i]->getId() << " " << students[i]->getFIO() << " average mark: " << students[i]->averageMark() << endl;
	}

	fout << endl << endl;
	fout.close();
}