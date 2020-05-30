#include <sstream>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Student.h"
#include "Group.h"
#include "Deanery.h"
using namespace std;

int main() {
	Deanery imikn("students.txt", "specs.txt");

	imikn.addMarksAll(5);
	imikn.headElectionAll();
	imikn.studentInfo("Allison Matthew");
	imikn.groupInfo("18PMI-1");
	imikn.changeGroup("Allison Matthew", "18BI-1");
	imikn.removeStudentsForPoorMarks(4);
	imikn.groupInfo("18PMI-1");
	imikn.saveToFile("students_output.txt");
	

	return 0;
}