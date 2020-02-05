#include <vector>
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

using namespace std;

int main() {
	/*
	Student student(12, "234");
	cout << student.getId() << " " << student.getFio() << endl;
	student.addMark(18);
	cout << student.getAvr() << endl;
	Group group("23");
	cout << group.addStudent(&student) << endl;
	cout << group.addStudent(&student) << endl;
	cout << group.searchStudent("2").size() << endl;
	Student student2(13, "234");
	cout << group.setHead(&student2) << endl;
	cout << group.eraseStudent(&student2) << endl;
	group.searchStudent(12)->addMark(5);
	group.searchStudent(12)->addMark(7);
	group.searchStudent(12)->addMark(9);
	cout << group.getAvr() << endl;
	group.setHead(&student);
	cout << group.getHead() << endl;
	group.eraseStudent(group.searchStudent(12));
	cout << group.getHead() << endl;
	*/
	cout << "START" << endl;
	Deanery deanery;
	deanery.extractDataFromFile("C:\\www\\testu.txt");
	deanery.electionHead();
	cout << deanery.searchGroup("rt");
	cout << deanery.searchGroup("uoi");
	cout << deanery.eraseWithBadMarks(2.0);
	deanery.randMarks();
	cout << deanery.eraseWithBadMarks(9.0);
	deanery.getStatistics();
	deanery.electionHead();
	return 0;
}

