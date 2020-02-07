#include "gtest/gtest.h"
#include "Dean.h"
#include "Student.h"
#include "Group.h"
#include <string>




system("chcp 1251");

TEST(testStudent, init1) {
	Student student1(0, "Artem", "Group");
	Student student2(1, "Anton", "Group");
	Student student3(2, "Nikita", "Group1");
	EXPECT_EQ(0, student1.get_id());
	EXPECT_EQ(2, student3.get_id());
}

TEST(testGroup, init4) {
	Group group("18PMI");
	group.add_Student("Anton");

	EXPECT_EQ(1, group.get_size());
	EXPECT_EQ(0, group.search_Student("Anton")->get_id());
}

TEST(testGroup, init2) {
	Group group("Group");
	group.add_Student("Anton");

	EXPECT_EQ("Group", group.get_title());
	EXPECT_EQ(1, group.get_size());
}

TEST(testDean, init3) {
	Group group1("Group1");
	group1.add_Student("Anton");
	Group group2("Group2");
	group1.add_Student("Artem");
	Group group3("Group3");
	group1.add_Student("Nikita");
	EXPECT_EQ(3, group1.get_size());
	EXPECT_EQ(0, group3.get_size());
}