#include "gtest/gtest.h"
#include "deanery.h"

TEST(lab5, first_check) {
	Student* student = new Student(1234, "Nick F");
	string str = student->getFIO();
	EXPECT_EQ(str, "Nick F");
	EXPECT_EQ(234, student->getID());
}




