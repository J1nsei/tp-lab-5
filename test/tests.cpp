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
	string filename = "students1.txt";
	Dean dean(filename);

	EXPECT_EQ(29, dean.find_group("18олх-1")->get_size());
	EXPECT_EQ(48, dean.find_group("18олх-2")->get_size());
	EXPECT_EQ(nullptr, dean.find_group("18ох-3"));
}