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
	dean.createGroups();
	dean.createStudents();
	dean.initiateHeadChoice();
	dean.studentDismissal(0, 1);
	dean.studentTransfer(0, 2, 1);
	dean.studentDismissalProgressless();
	dean.statistics();

	/*Group testGroup("testGroup");
	Student* first = new Student("Паша Зайцев");
	Student* second = new Student("Маша Лисичкина");
	first->addMark(5);
	first->addMark(6);
	second->addMark(7);
	second->addMark(8);
	
	testGroup.recieveStudent(first);
	testGroup.recieveStudent(second);
	testGroup.addRandomMarks();

	cout << testGroup.averageGroupMark() << endl;*/
	
}