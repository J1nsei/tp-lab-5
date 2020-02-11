#include "gtest/gtest.h"
#include "student.h"
#include "group.h"
#include "deanery.h"

TEST(lab5, task1)
{
	Student* student = new Student("Barbara Claribel", 1);
	student->add_mark(10);
	student->add_mark(9);
	student->add_mark(8);
	float gpa = student->get_average();
	EXPECT_EQ(9.0, gpa);
}


TEST(lab5, task2)
{
	Student* student = new Student("Barbara Claribel", 1);
	Group* group = new Group("19PMI-1", "Math");
	group->add_student(student);
	group->elect_head();
	EXPECT_EQ("Barbara Claribel", group->get_head());
}
