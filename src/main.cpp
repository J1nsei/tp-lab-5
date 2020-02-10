
#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using namespace std;

#define test_in "C://test//test.txt"
#define test_out "C://test//test_out.txt"

int main(int argc, char** argv) { // test1.exe test_in.txt test_out.txt
	cout << "START TESTING FOR WINDOWS" << endl;
	char* testFilePath;
	if (argc == 1) {
		testFilePath = test_in;
	}
	else {
		testFilePath = argv[1];
	}
	Deanery deanery;
	deanery.extractDataFromFile(testFilePath);
	deanery.electionHead();
	cout << deanery.searchGroup("rt");
	cout << deanery.searchGroup("uoi");
	cout << deanery.eraseWithBadMarks(2.0);
	deanery.randMarks();
	deanery.getStatistics();
	deanery.electionHead();
	deanery.changeGroup(deanery.searchStudent("Fr")[0], deanery.searchGroup("uoi"));
	string testOutPath;
	if (argc <= 2) {
		testOutPath = test_out;
	}
	else {
		testOutPath = (string)argv[2];
	}
	deanery.saveDataInFile(test_out);
	return 0;
}

