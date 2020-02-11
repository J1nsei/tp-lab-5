#include "student.h"
#include "group.h"
#include "deanery.h"
#include <Windows.h>

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Deanery deanery = Deanery();
	deanery.createGroups("groups.txt");
	deanery.createStudents("students.txt");
	cout << deanery.getGroups().size() << endl;
	deanery.setHeads();
	deanery.addMarks(10);
	deanery.getStatistics();
	deanery.transferStudent("Hancock Martin Charles", "18PI-1");
	deanery.removeStudents(2.2);
	deanery.saveData();
}
