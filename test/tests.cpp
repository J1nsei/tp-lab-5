#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testGroup, title) {
	Group group("title", "spec");
	EXPECT_EQ("title", group.GetTitle());
}

TEST(testGroup, studentPointer) {
	Group group("title", "spec");
	Student student(0, "A B C", NULL);
	group.AddStudent(&student);	
	EXPECT_EQ(group.FindStudent("A B C"), &student);
}

TEST(testStudent, fio) {
	Student student(0, "A B C", NULL);
	EXPECT_EQ("A B C", student.GetFio());
}

TEST(testStudent, id) {
	Student student(0, "A B C", NULL);
	student.SetId(8);
	EXPECT_EQ(8, student.GetId());
}

TEST(testStudent, average) {
	Student student(0, "A B C", NULL);
	student.AddMark(6);
	EXPECT_EQ(6.0, student.CountAverage());
	student.AddMark(8);
	EXPECT_EQ(7.0, student.CountAverage());
}

