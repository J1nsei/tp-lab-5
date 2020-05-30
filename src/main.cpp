#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Group.h"
#include "Dean.h"
using namespace std;

vector <string> split(string buffer, char del)
{
	vector <string> result;
	string temp;
	stringstream stream;
	stream << buffer;
	while (getline(stream, temp, del))
		result.push_back(temp);
	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Dean IMIKN("IMIKN");
	ifstream fin("students.txt");
	ifstream fingroups("groups.txt");
	string temp;
	while (getline(fingroups, temp))
	{
		vector<string> buf = split(temp, ';');
		IMIKN.create_group(buf[0], buf[1]);
	}
	int id = 0;
	while (getline(fin, temp))
	{
		id++;
		vector<string> buf = split(temp, ';');
		IMIKN.add_student_to_group(buf[0], buf[1]);
	}
	IMIKN.print_data();
	
}