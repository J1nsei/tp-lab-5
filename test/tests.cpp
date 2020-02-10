#include "gtest/gtest.h"
#include "dean.h"
#include "student.h"
#include "group.h"

TEST (stud, id) {
	Student* stud = new Student ("Soloviova Alina", 1);
	int id = stud->getId();
	EXPECT_EQ(0,id);
}
TEST (deanery, changeofgroup) {
	Deanery hse;
	Group* group1 = hse.createGroup ("group1","spec1");
	Group* group2 = hse.createGroup ("group2","spec2");
	hse.createStudent(1,"Soloviova Alina",group1);
	hse.changeGroup("Soloviova Alina", group1,group2);
	string name = group2->getStudents() [1]->getName();
	EXPECT_EQ("Soloviova Alina", name);
}
TEST (deanery, averageforstudents) {
	Deanery hse;
	Group* group = hse.creareGroup ("group","spec");
	hse.createStudent(1,"Soloviova Alina",group);
	hse.addMarks(group,"Soloviova Alina",4);
	hse.addMarks(group,"Soloviova Alina",5);
	hse.addMarks(group,"Soloviova Alina",6);
	double avermark = hse.getAverageStudent(group,"Soloviova Alina");
	EXPECT_EQ(5,avermark);
}