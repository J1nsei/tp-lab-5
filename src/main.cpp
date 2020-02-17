#include"Deanery.h"
#include"Group.h"
#include"Student.h"
#include<iostream>

using namespace std;

int main() {
	Deanery dean1;
	dean1.CreateStudents("input.txt");
	dean1.GenerateMarks("18PMI-1");
	dean1.GenerateMarks("18PMI-2");
	dean1.GenerateMarks("18PI-1");
	dean1.GenerateMarks("18PI-2");
	Group* testGroup = dean1.findGroup("18PMI-1");
	if (testGroup)
	{
		cout << "Group has been found" << endl;
		cout << dean1.GetStatsGroup("18PMI-1") << endl;
	}
	else
	{
		cout << "No such group!" << endl;
	}
	dean1.MoveStudent("18PMI-1", "18PI-1","O’Brien’ Joshua");
	dean1.Print();
	return 0;
}