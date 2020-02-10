#include "gtest/gtest.h"
#include "dean.h"


TEST(stud, id){
	Student* stud = new Student("Arakcheev Artem", 0);
	int id = stud->get_id();
	EXPECT_EQ(0, id);
}

TEST(deanery, changegroup){
	Deanery hse;
	Group* group1 = hse.createGroup("group1", "spec1");
	Group* group2 = hse.createGroup("group2", "spec2");
	hse.createStudent(0, "Arakcheev Artem", group1);
	hse.changeGroup("Arakcheev Artem", group1, group2);
	string name = gr2->getStudents()[0]->getName();
	EXPECT_EQ("Arakcheev Artem", name);
}

TEST(deanery, averageforstud){
	Deanery hse;
	Group* group = hse.createGroup("group", "spec");
	hse.createStudent(0, "Arakcheev Artem", group);
	hse.addMarks(group, "Arakcheev Artem", 4);
	hse.addMarks(group, "Arakcheev Artem", 6);
	double mark = hse.getAverageStudent(group, "Arakcheev Artem");
	EXPECT_EQ(5, mark);
}
