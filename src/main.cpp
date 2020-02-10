#include <iostream>
#include "Deanery.h"
using namespace std;

int main()
{

	Deanery Deanery("students.txt", "groups.txt");


	Deanery.MakeStudents();
	Deanery.MakeGroups();
	Deanery.AddMarks();
	Deanery.HeadInit();
	Deanery.StudentDelete();
	Deanery.New();
	Deanery.PrintInf();
	
	return 0;
}