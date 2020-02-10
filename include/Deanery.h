#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Group.h"
#include "Student.h"
#include <random>
#include <time.h>
using namespace std;
class Deanery
{
private:
	int nextId = 0;
	vector<Group*> groups;
public:
	Deanery();
	~Deanery();
	void updateStudents();
	void printAllStudents();
	void getRandomMark(Student* student);
	void killBadStudents();
	void saveDates();
	void updateAllHead();
};

