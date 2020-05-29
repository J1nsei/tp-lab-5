#include "gtest/gtest.h"
#include "Dean.h"
#include "Student.h"
#include "Group.h"
#include <string>


TEST(testStudent, init1) {
	Student student1(0, "Artem", "Group");
	Student student2(1, "Anton", "Group");
	Student student3(2, "Nikita", "Group1");
	EXPECT_EQ(0, student1.get_id());
	EXPECT_EQ(2, student3.get_id());
}

TEST(testGroup, init2) {
	Group group("18PMI");
	group.add_Student("Anton");

	EXPECT_EQ(1, group.get_size());
}

TEST(testGroup, init3) {
	Group group("Group");
	group.add_Student("Anton");

	EXPECT_EQ("Group", group.get_title());
	EXPECT_EQ(1, group.get_size());
}
