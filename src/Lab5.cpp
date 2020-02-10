#include <iostream>
#include "Deanery.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	Deanery deanery;
	deanery.updateStudents();
	deanery.printAllStudents();
}




