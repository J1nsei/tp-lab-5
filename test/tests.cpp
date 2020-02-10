#include "gtest/gtest.h"
#include "dean.h"
#include "student.h"
#include "group.h"
TEST (deanery, deanery){
	Deanery hse;
	Group* PMI = hse.createGroup("18-PMI", "Прикладная математика и информатика");
	EXPECT_EQ("18-PMI",PMI->getTitle());
	Group* PI = hse.createGroup("18-PI", "Программная инженерия");
	EXPECT_EQ("Программная инженерия",PI->getSpec());
	Group* BI = hse.createGroup("18-BI", "Бизнес информатика");
	hse.createStudent(12, "Данилов Сергей Дмитриевич", BI);
	BI->chooseHead();
	EXPECT_NE(NULL,BI->getHead());
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
	EXPECT_NE(NULL,BI->searchStudentName("Казанцев Иннокентий Алексеевич"));
	EXPECT_NE(NULL,BI->searchStudentId(1));
	
}