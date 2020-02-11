#include "gtest/gtest.h"
#include "dean.h"


TEST(stud, id){
	Student* stud = new Student("Огурлиев Анзор", 0);
	int id = stud->getId();
	EXPECT_EQ(0, id);
}

TEST(deanery, changegroup){
	Deanery hse;
	Group* group1 = hse.createGroup("group1", "spec1");
	Group* group2 = hse.createGroup("group2", "spec2");
	hse.createStudent(0, "Огурлиев Анзор", group1);
	hse.changeGroup("Огурлиев Анзор", group1, group2);
	string name = group2->getStudents()[0]->getName();
	EXPECT_EQ("Огурлиев Анзор", name);
}

TEST(deanery, averageforstud){
	Deanery hse;
	Group* group = hse.createGroup("group", "spec");
	hse.createStudent(0, "Огурлиев Анзор", group);
	hse.addMarks(group, "Огурлиев Анзор", 4);
	hse.addMarks(group, "Огурлиев Анзор", 6);
	double mark = hse.getAverageStudent(group, "Огурлиев Анзор");
	EXPECT_EQ(5, mark);
}

TEST (deanery, compareoftitles){
	Deanery hse;
	Group* PMI = hse.createGroup("18-PMI", "Прикладная математика и информатика");
	EXPECT_EQ("18-PMI",PMI->getTitle());
}
TEST (deanery, compareofspecializations) {
	Deanery hse;
	Group* BI = hse.createGroup("18-BI", "Бизнес-информатика");
	EXPECT_EQ("Бизнес-информатика",BI->getSpec());
}
TEST (deanery, chooseofhead) {
	Deanery hse;
	Group* FM = hse.createGroup("18-FM", "Фундаментальная математика");
	hse.createStudent(1,"Данилов Сергей Дмитриевич", FM);
	FM->chooseHead();
	EXPECT_EQ("Данилов Сергей Дмитриевич", FM->getHead()->getName());
}