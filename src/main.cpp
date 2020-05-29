#include <iostream>
#include "Deanery.h"
using namespace std;

int main()
{
	Deanery deanery("students.txt", "groups.txt");
	deanery.MakeStudents();
	deanery.MakeGroups();
	deanery.AddMarks();
	deanery.HeadInit();
	deanery.Statistics();
	deanery.StudentException();
	deanery.Update("output.txt");
	deanery.PrintData();
	return 0;
}
