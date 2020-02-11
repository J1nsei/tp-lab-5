#include "decan.h"

int main()
{
	Decan decan("../student.txt", "../groups.txt");
	decan.addStudent();
	decan.addGroup();
	return 0;
}