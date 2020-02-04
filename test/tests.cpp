#include "gtest/gtest.h"
#include "Stduent.h"
#include "Group.h"

TEST(student, student_create) {
	Student student(1, "wer");
	EXPECT_EQ("wer", student.getFio());
	EXPECT_EQ(1, student.getId());
	EXPECT_EQ(NULL, student.getGroup());

	EXPECT_EQ(-1, student.addMark(-1));
	EXPECT_EQ(-1, student.addMark(11));
	EXPECT_EQ(0, student.getAvr());
	EXPECT_EQ(1, student.addMark(0));
	EXPECT_EQ(1, student.addMark(10));
	EXPECT_EQ(5.0, student.getAvr());

	EXPECT_EQ(-1, student.setGroup(NULL));
	Group group("23");
	EXPECT_EQ(1, student.setGroup());
	EXPECT_EQ("23", student.getGroup()->getTitle());
}

TEST() {

}

TEST() {

}

TEST() {

}

TEST() {
	
}
