#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

//Test(student, num) {
//	Student student(11, "Vict Alfa Samka");
//	student.AddMark();
//	EXPECT_EQ(1, student.MarkSize());
//}

TEST(testStudent, fio) {
	Student student(11, "Vict Alfa Samka");
	EXPECT_EQ("Vict Alfa Samka", student.GetFio());
}

TEST(testStudent, id) {
	Student student(11, "Vict Alfa Samka");
	EXPECT_EQ(11, student.GetId());
}

TEST(testGroup, size) {
	Group group("18pml2");
	Student student(11, "Vict Alfa Samka");
	group.AddStudent(&student);
	EXPECT_EQ(1, group.GetSize());
}

//
//TEST(testStudent, average) {
//	Student student(11, "Vict Alfa Samka");
//	student.AddMark(9);
//	EXPECT_EQ(9.0, student.AvMark());
//}