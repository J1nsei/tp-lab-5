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

/*For WINDOWS ONLY!, for linux define it in arguments*/
char* test_in = (char*)"C://test//test.txt";
char* test_out = (char*)"C://test//test_out.txt";

int main(int argc, char** argv) { // test1.exe test_in.txt test_out.txt 
	cout << "START TESTING" << endl;
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
	cout << deanery.searchGroup("PI0") << endl;
	cout << deanery.searchGroup("PI2") << endl;
	cout << deanery.eraseWithBadMarks(2.0) << endl;
	deanery.randMarks();
	deanery.getStatistics();
	deanery.electionHead();
	char* testOutPath;
	if (argc <= 2) {
		testOutPath = test_out;
	}
	else {
		testOutPath = argv[2];
	}
	deanery.saveDataInFile(test_out);
	return 0;
}

