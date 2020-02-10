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
TEST(task2, search_stud) {
	Student student2(0, "Nicolay Sharonov");
	Group group("18PMI");
	group.addStudent(&student2);
	EXPECT_EQ(1, group.search_stud(0));
}
TEST(task3, del_stud) {
	Group group("18PMI2");
	Student student1(0, "Katya Malysheva");
	Student student2(1, "Nicolay Sharonov");
	group.addStudent(&student1);
	group.addStudent(&student2);
	group.del_stud(0);
	EXPECT_EQ(0, group.search_stud(0));

}
TEST(task4, avg_group_mark) {
	Group group("18PMI2");
	Student student1(0, "Katya Malysheva");
	Student student2(1, "Nicolay Sharonov");
	group.addStudent(&student1);
	group.addStudent(&student2);
	for (int i = 0; i < 10; i++) {
		student1.addMark(0);
		student2.addMark(10);
	}
	student1.cnt_aver_marks();
	student2.cnt_aver_marks();

	EXPECT_EQ(5, group.avg_group_mark());

}
TEST(task5, moving) {
	Deanery REALDEANERY("students.txt", "groups.txt");

	REALDEANERY.create_students();
	REALDEANERY.create_groups();
	REALDEANERY.move_student("Константинов Николай", "18PMI3");
	EXPECT_EQ(0, 18PMI1.search_stud(1));
	EXPECT_EQ(1, 18PMI3.search_stud(1));

}