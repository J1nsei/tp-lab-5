#include "pch.h"
#include "gtest/gtest.h"
#include "../decan/decan.h"
#include "../decan/group.h"
#include "../decan/student.h"
#include <string>

TEST (testStudent, getName) 
{
	Student student("A A A", 0);
  EXPECT_EQ("A A A", student.getName());
}

TEST(testStudent, getID)
{
	Student student("A A A", 0);
	EXPECT_EQ(0, student.getID());
}

TEST(testGroup, getSize)
{
	Student student("A A A", 0);
	Group group("A");
	group.addStudent(&student);
	EXPECT_EQ(1, group.getSize());
}