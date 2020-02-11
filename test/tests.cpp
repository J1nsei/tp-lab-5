#include "gtest/gtest.h"
#include "deanery.h"

TEST(lab5, first_check) {
	Student* student = new Student(1234, "Nick F");
	string str = student->getFIO();
	EXPECT_EQ(str, "Nick F");
	EXPECT_EQ(1234, student->getID());
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

TEST(lab5, dean_check){
	Deanery d;
	Group *G1 = new Group("G1");
	Group *G2 = new Group("G2");
	Student *s = new Student(1,"A A");
	G1->addStudent(s);
	s = new	Student(2,"B B");
	G1->addStudent(s);
	s = new Student(3,"F F");
	Student *s2 = d.findStudent(2);
	EXPECT_EQ(G1->findStudent(2), s2);
	EXPECT_EQ(G1,s2->getGroup());
	d.transferStudent(G1,G2,s2);
	EXPECT_EQ(nullptr,G1->findStudent(2));
	EXPECT_EQ(s2,G2->findStudent(2));

}




