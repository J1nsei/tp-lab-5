#include "gtest/gtest.h"
#include "Header.h"
#include <string>

TEST(testStudent, avg_mark) {
	Student student1(0, "Katya Malysheva");
	for (int i = 0; i < 10; i++) {
		student1.addMark(i);
	}
	EXPECT_EQ(4.5, student1.cnt_aver_marks());
}
TEST(testGroup, init) {
	Student student2(0, "Nicolay Sharonov");
	Group group("18PMI");
	group.addStudent(&student2);

	EXPECT_EQ("Студент Nicolay Sharonov найден", group.search_stud(0));
}