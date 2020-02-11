#include <iostream>
#include <fstream>
#include <cstdio>

#include "Deanery.h"
#include "Group.h"
#include "Student.h"

using namespace std;

void Deanery::createGroups() {
	ifstream fin;
	fin.open("src/Groups_list.txt", ifstream::in);
	string* _tmp = new string;
	for (int i = 0; i < 4; i++) {
		if (/*fin.getline() != EOF*/ !fin.eof()) {
			fin >> *_tmp;
			groups.push_back(Group(*_tmp));
		}
	}
	delete(_tmp);

	for (int i = 0; i < 4; i++) {
		groups[i].printTitle();
	}

	fin.close();
}

void Deanery::createStudents() {
	ifstream fin;
	fin.open("src/Students_list.txt", ifstream::in);
	string* _tmp = new string;
	string *_tmpFull = new string;
	for (int i = 0; i < groups.size(); i++) {
		for (int j = 0; j < 25; j++) {
			fin >> *_tmp;
			*_tmpFull += *_tmp + " ";
			fin >> *_tmp;
			*_tmpFull += *_tmp + " ";
			fin >> *_tmp;
			*_tmpFull += *_tmp;
			groups[i].addStudent(*_tmpFull);
			*_tmpFull = "";
		}
	}
	delete(_tmpFull);
	delete(_tmp);

	for (int i = 0; i < 4; i++) {
		groups[i].printStudents();
		cout << endl;
	}

	fin.close();
}

void Deanery::initiateHeadChoice() {
	Student* _showHead;
	cout << "Heads:" << endl;
	for (int i = 0; i < 4; i++) {
		_showHead = groups[i].headChoice();
		cout << _showHead->getFIO() << endl;
	}
}

void Deanery::addRandomMarkAllStutents() {
	for (int i = 0; i < 4; i++) {
		groups[i].addRandomMarks();
	}
}

void Deanery::studentDismissal(int group, int id) {
	Student* _toDismiss = groups[group].dismissalStudent(id);
	delete(_toDismiss);
}

void Deanery::studentTransfer(int group, int id, int groupDestination) {
	/*Student* _toTransfer = groups[group].dismissalStudent(id);*/
	if (groups[group].searchStudent(id) != nullptr) {
		groups[groupDestination].recieveStudent(groups[group].dismissalStudent(id));
	}
	else {
		cout << "Unable to transfer student" << endl;
	}
}

void Deanery::studentDismissalProgressless() {
	vector <Student*> unluckyStudents;
	for (int i = 0; i < groups.size(); i++) {
		groups[i].studentDismissalProgressless();
		cout << endl << endl;
		groups[i].printStudents();
	}
}

void Deanery::statistics() {
	ofstream fout;
	fout.open("statistics/statistics.txt", ofstream::out);
	fout.close();
	//fout << "man, give me something" << endl;
	//fout << "yeah, soon";

	for (int i = 0; i < groups.size(); i++) {
		groups[i].statistics();

	}

	
}
