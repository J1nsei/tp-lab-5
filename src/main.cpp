#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <clocale>
#include "dean.h"
#include "group.h"
#include "student.h"

using namespace std;

int main(){
	system("chcp 1251");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	Deanery hse;
	Group* PMI = hse.createGroup("18-PMI", "Прикладная математика и информатика");
	Group* PI = hse.createGroup("18-PI", "Программная инженерия");
	Group* BI = hse.createGroup("18-BI", "Бизнес информатика");
	ifstream inp("students.txt");
	int id = 0;
	char div = ':';
	while(!inp.eof()){
		string buf;
		getline(inp, buf, '\n');
		vector<string> data;
		string dat;
		istringstream str(buf);
		while (getline(str, dat, div))
			data.push_back(dat);
		if (data[1] == "18-PMI"){
			hse.createStudent(id, data[0], PMI);
			for (int i = 0; i < 5; i++)
				hse.addMarks(PMI, data[0], rand() % 10);
		}
		if (data[1] == "18-PI"){
			hse.createStudent(id, data[0], PI);
			for (int i = 0; i < 5; i++)
				hse.addMarks(PI, data[0], rand() % 10);
		}
		if (data[1] == "18-BI"){
			hse.createStudent(id, data[0], BI);
			for (int i = 0; i < 5; i++)
				hse.addMarks(BI, data[0], rand() % 10);
		}
		id++;
	}
	hse.deleteForMarks(PMI);
	hse.deleteForMarks(PI);
	hse.deleteForMarks(BI);
	hse.initializeHeadmen(PMI);
	hse.initializeHeadmen(PI);
	hse.initializeHeadmen(BI);
	hse.saveData();
	hse.printData();
}
