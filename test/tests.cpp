#include "gtest/gtest.h"
#include "deanery.h"

TEST(lab5, first_check) {
	Student* student = new Student(1234, "Nick F");
	string str = student->getFIO();
	EXPECT_EQ(str, "Nick F");
	EXPECT_EQ(234, student->getID());
}

TEST(lab5, group_check){
	Group *group = new Group("G1");
	EXPECT_EQ("G1",group->getTitle());
	group->setSpec("IT");
	EXPECT_EQ("IT",group->getSpec());
	Student *s = new Student(123,"Fedor H");
	s->addToGroup(group);
	group->addStudent(s);
	EXPECT_EQ(group,s->getGroup());
	group->setHead(s);
	EXPECT_EQ(s,group->getHead());
}






