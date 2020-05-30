#include <iostream>
#include "Deanery.h"
using namespace std;

int main()
{

	Deanery Deanery("students.txt", "groups.txt");


	Deanery.CreateStudents();
	Deanery.CreateGroups();
	Deanery.AddMarks();
	Deanery.HeadInit();
	Deanery.StudentDelete();
	Deanery.New();
	Deanery.PrintInformation();

	return 0;
}