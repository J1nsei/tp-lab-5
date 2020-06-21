#include <iostream>
#include "dean.h"
#include <string>
#include <vector>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "ru");
	string fname = "Groups.txt";
	string fname2 = "Students.txt";
	Deanery dean;
	dean.crGroups(fname);
	dean.crStudents(fname2);
	dean.addRandMarks();
	dean.choiceGrHead();
	dean.getStats();
	dean.saveNewData();
	return 0;
}