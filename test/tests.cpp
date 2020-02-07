#include "gtest/gtest.h"
#include "Deanery.h"

TEST(student, get_fio)
{
	Student* stud = new Student(0, "FIO of student");
	string FIO = stud->get_fio();
	EXPECT_EQ("FIO of student", FIO);
}