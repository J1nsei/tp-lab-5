#include "gtest/gtest.h"
#include "student.h"
#include <string>

TEST(testStudent, init) 
{
	Student *s = new Student(5,"Vasya Petrov");
	int id;
	id = s->get_id();
	EXPECT_EQ(5, id);
}