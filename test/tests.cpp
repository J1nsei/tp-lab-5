#include "gtest/gtest.h"
#include "student.h"
#include "group.h"
#include "dean.h"
#include <string>

TEST(student,test1)
{
	Student stud("Testing Qwerty Prog", 113);
	string st_name = "Testing Qwerty Prog";
	EXPECT_EQ(st_name, stud->getFio());
}

TEST(student, test2)
{
	Student stud("Testing Qwerty Prog", 113);
	int st_id = 113;
	EXPECT_EQ(st_id, stud->getId());
}

TEST(group, test1)
{
	Student stud("Testing Qwerty Prog", 113);
	Group grp("title", "spec");
	grp.addStudent(stud);
	int st_id = 113;
	EXPECT_EQ(st_id, grp->searchStudentFIO("Testing Qwerty Prog")->getId());
}

TEST(group, test2)
{
	Student stud("Testing Qwerty Prog", 113);
	Group grp("title", "spec");
	grp.addStudent(stud);
	str = "title spec";
	EXPECT_EQ(str,grp.info());
}