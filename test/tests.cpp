
#include "gtest/gtest.h"
#include "deanery.h"

TEST(lab5, task1)
{
	Student* student = new Student(0, "jhvhbnvc");
	string fio = student->getFio();
	EXPECT_EQ("jhvhbnvc", fio);
	int id = student->getId();
	EXPECT_EQ(0, id);
}

TEST(lab5, task2)
{
	Group* group = new Group("dsnk", "jhvhbnvc");
	string title = group->getTitle();
	EXPECT_EQ("dsnk", title);
	string spec = group->getSpec();
	EXPECT_EQ("jhvhbnv", spec);
}

TEST(lab5, task3)
{
	Group* group = new Group("dsnk", "jhvhbnvc");
	Student* student = new Student(0, "jhvhbnv");
	group->add_student(student);
	Student* stud = group->find_student_fio("jhvhbnv");
	EXPECT_EQ(stud, student);
	Student* stud = group->find_student_id(0);
	EXPECT_EQ(stud, student);
}

TEST(lab5, task4)
{
	Deanery dean;
	Group* group = dean.make_groups("dsnk", "jhvhbnvc");
	dean.make_students(0, "jhvhbnv", group);
	dean.make_head(group);
	Student* head = group->getHead();
	Student* exp = group->getStudents()[0];
	EXPECT_EQ(head, exp);
}

TEST(lab5, task5)
{
	Deanery dean;
	Group* group = dean.make_groups("dsnk", "jhvhbnvc");
	dean.make_students(0, "jhvhbnv", group);
	dean.add_mark(group, "jhvhbnv", 3);
	dean.add_mark(group, "jhvhbnv", 8);
	float mark = dean.get_average_mark_student(group, "jhvhbnv");
	EXPECT_EQ(5.5, mark);
}