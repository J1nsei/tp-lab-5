#include "decan.h"

int main()
{
	Decan decan("../student.txt", "../groups.txt");
	decan.addStudent();
	decan.addGroup();
	decan.setHead();
	decan.setMarks();
	decan.setMarks();	
	decan.update("stat.txt");
	decan.printGroup();
	return 0;
}