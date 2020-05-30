#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

#include "Deanery.h"
#include "Group.h"
#include "Student.h"

using namespace std;

vector<string> split(const string& s, char delimiter) {
	vector <string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int main() {
	srand(time(0));
	/*system("chcp 1251");
	//ifstream studentsList("bd_test.txt");
	//while (!studentsList.eof()) {
	//	string buf;
	//	getline(studentsList, buf, '\n');
	//	vector <string> data = split(buf, ':');
	//	for (auto s : data)
	//		cout << s << " ";
	//	cout << endl;
	//}*/

	//Student Pasha;
	//
	//Pasha.showMarks();
	//cout << Pasha.averageMark() << endl;
	///*for (int i = 0; i < 50; i++) {
	//	int randNumMarks = rand() % 10 + 5;
	//	cout << randNumMarks << " ";
	//}*/

	system("chcp 1251");

	Deanery dean;
	cout << "Initialising groups and students:" << endl;
	dean.createGroups();
	dean.createStudents();

	cout << endl << "Chosing Heads in each group:" << endl;
	dean.initiateHeadChoice();

	cout << endl << "Deleting student: 1 group (18AI), id:1" << endl;
	dean.studentDismissal(0, 1);

	cout << "Transfer student: from 1 group (18AI), id:2 ---> to 2 group (18BI)" << endl << endl;
	dean.studentTransfer(0, 2, 1);

	cout << "Dismiss all students with average mark < 4.5 / print and save final statistics" << endl;
	dean.studentDismissalProgressless();
	dean.statistics();
	
}