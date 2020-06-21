#include "gtest/gtest.h"
#include "stdntent.h"
#include "group.h"
#include "dean.h"
#include <string>

TEST(stdntent,test1)
{
	stdntent stdnt(113,"Testing Qwerty Prog");
	string st_name = "Testing Qwerty Prog";
	EXPECT_EQ(st_name, stdnt.getFio());
}

TEST(stdntent, test2)
{
	stdntent stdnt(113, "Testing Qwerty Prog");
	int st_id = 113;
	EXPECT_EQ(st_id, stdnt.getId());
}

TEST(group, test1)
{
	stdntent stdnt(113, "Testing Qwerty Prog");
	Group grp("title", "spec");
	grp.addstdntent(&stdnt);
	int st_id = 113;
	EXPECT_EQ(st_id, grp.searchstdntentFIO("Testing Qwerty Prog")->getId());
}

TEST(group, test2)
{
	stdntent stdnt(113, "Testing Qwerty Prog");
	Group grp("title", "spec");
	grp.addstdntent(&stdnt);
	string str = "title spec";
	EXPECT_EQ(str,grp.info());
}