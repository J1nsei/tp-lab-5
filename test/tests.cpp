#include "gtest/gtest.h"
#include "Header.h"
#include <string>

TEST(task1, avg_mark) {
	Student student1(0, "Katya Malysheva");
	for (int i = 0; i < 10; i++) {
		student1.addMark(i);
	}
	EXPECT_EQ(4.5, student1.cnt_aver_marks());
}
