#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>
TEST(testGroup, size) {
	Group group("18pi2");
	Student student(23, "Lena Bobrova");
	group.AddStudent(&student);
	EXPECT_EQ(1, group.GetSize());
}



TEST(testMarks, size) {
	Student student(11, "Lena Bobrova");
	student.AddMark();
	student.AddMark();
	student.AddMark();
	EXPECT_EQ(3, student.MarkSize());
}

TEST(testGroup, find) {
	Student student1(22,"Ann Stone");
	Student student2(13,"Mark Domn");
	Student student3(5,"Loran Dru");
	Group group1("19pmi");
	group1.AddStudent(&student1);
	
	EXPECT_TRUE(group1.SearshStud(22));
}