#include "gtest/gtest.h"
#include "../decan/decan.h"
#include "../decan/group.h"
#include "../decan/student.h"
#include <string>

TEST (testStudent, getName) 
{
	Student student("Андрей Андреевич Андреев", 0);
  EXPECT_EQ("Андрей Андреевич Андреев", student.getName());
}

TEST(testStudent, getID)
{
	Student student("Андрей Андреевич Андреев", 0);
	EXPECT_EQ(0, student.getID());
}

TEST(testGroup, getSize)
{
	Student student("Андрей Андреевич Андреев", 0);
	Group group("Group");
	group.addStudent(&student);
	EXPECT_EQ(1, group.getSize());
}