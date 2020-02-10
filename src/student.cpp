#include "student.h"
#define NUMBER_OF_MARKS 10

unsigned int new_id = 0;

Student::Student() {
	name = "Unknown";
	group = "Unknown";
	id = -1;
}

Student::Student(string init_name, string init_group) {
	name = init_name;
	group = init_group;
	id = ++new_id;
};

void Student::setMarks() {
	
	for (int i = 0; i < NUMBER_OF_MARKS; i++) marks.push_back(rand() % 4 + 2);
}

string Student::getStudentName()
{
	return name;
}

int Student::getStudentId()
{
	return id;
}

double Student::countAverageMark()
{
	double sum = 0;
	for (int i = 0; i < NUMBER_OF_MARKS; i++)
		sum += marks[i];
	return sum / NUMBER_OF_MARKS;
}

void Student::setGroup(string new_group)
{
	group = new_group;
}


void Student::printInformation()
{
	cout << name << endl;
	cout << group << endl;
	cout << id << endl;
	for (int i = 0; i < 10; i++)
		cout << marks[i] << ' ';
	cout << endl;
	cout << this->countAverageMark() << endl;
}

vector<int> Student::getMarks()
{
	return marks;
}

string Student::getStudentGroup()
{
	return group;
}

