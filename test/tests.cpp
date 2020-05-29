#include "gtest/gtest.h"
#include "Dean.h"
#include <string>

TEST(testStudent, init) {
	Student student0;
	Student student1(0, "George Washington", "Group1");
	EXPECT_EQ(-1, student0.get_id());
	EXPECT_EQ(0, student1.get_id());
	EXPECT_EQ("Group1", student1.get_group());
}

TEST(testStudent, avg_mark) {
	Student student(0, "George Washington", "Group1");
	for (size_t i = 0; i < 10; i++) {
		student.set_mark(i);
	}
	EXPECT_EQ(4.5, student.average_mark());
}

TEST(testGroup, init) {
	Group group("18PMI", "Math");
	group.add_student("Alexey Scherbakov");

	EXPECT_EQ(1, group.get_size());
	EXPECT_EQ("Math", group.get_spec());
	EXPECT_EQ(0, group.find_student("Alexey Scherbakov")->get_id());
}

TEST(testGroup, expelling) {
	Group group("18PMI", "Math");
	group.add_student("George Washington");
	EXPECT_EQ(1, group.get_size());
	group.expel_student(0);
	EXPECT_EQ(nullptr, group.find_student("George Washington"));
}

TEST(testDean, transfer) {
	Group group1("18PMI", "Math"),
		group2("18PI", "Programming");
	group1.add_student("George Washington");
	Dean dean(group1);
	dean.add_group(group2);
	dean.student_transfer("George Washington", "18PMI", "18PI");
	EXPECT_EQ(dean.find_group("18PMI")->get_size(), 0);
	EXPECT_EQ(dean.find_group("18PI")->get_size(), 1);
}