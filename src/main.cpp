#include <iostream>
#include "Deanery.h"

using namespace std;

int main()
{
	Deanery deanery("students.txt", "groups.txt");

	deanery.makeStud();
	deanery.makeGroups();

	deanery.addMarks();
	deanery.leader();
	deanery.stat();

	deanery.exclusion();
	deanery.upd("students_list.txt");
	deanery.outputInform();

	return 0;
}