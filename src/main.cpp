#include <vector>
#include <iostream>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
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

	Deanery deanery;
	deanery.createGroup("test.txt");
	cout << deanery.getId();
	return 0;
}

