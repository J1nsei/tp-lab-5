#include "gtest/gtest.h"
#include "Classes.hpp"
#include "ctime"


TEST(student_test, FIO_check) {
	Student* st = new Student("1 Иванов Иван Иванович", NULL);
	EXPECT_EQ("Иванов", st->get_last_name());
	EXPECT_EQ("Иван", st->get_first_name());
	EXPECT_EQ("Иванович", st->get_second_name());
	EXPECT_EQ(1, st->get_id());
}

TEST(student_test, mean_check) {
	Student* st = new Student("1 Иванов Иван Иванович", NULL);
	srand(time(NULL));
	st->add_mark(4);
	st->add_mark(5);
	st->add_mark(6);
	EXPECT_EQ(5, st->get_mean());
}

TEST(student_test, head_check) {
	Student* st = new Student("1 Иванов Иван Иванович", NULL);
	EXPECT_EQ(false, st->is_group_head());
	st->set_as_head();
	EXPECT_EQ(true, st->is_group_head());
}

TEST(group_test, add_student_test) {
	Group* gr = new Group("18PI");
	Student* st = new Student("1 Иванов Иван Иванович", NULL);
	ASSERT_TRUE(gr->add_student(st));
}

TEST(group_test, transfer_test) {
	Group* gr1 = new Group("18PI");
	Group* gr2 = new Group("18FM");
	Student* st = new Student("1 Кузьмин Никита Сергеевич");
	gr1->add_student(st);
	gr1->transfer_to_group(1, gr2);
	ASSERT_FALSE(gr1->is_student_exist(1));
	ASSERT_TRUE(gr2->is_student_exist(1));
}

TEST(group_test, expell_test) {
	Group* gr = new Group("18PI");
	Student* st = new Student("1 Шабров Илья Дмитриевич");
	gr->add_student(st);
	ASSERT_TRUE(gr->is_student_exist(1));
	gr->expell_by_id(1);
	ASSERT_FALSE(gr->is_student_exist(1));
}

TEST(group_test, search_test) {
	Group* gr = new Group("18PI");
	Student* st1 = new Student("1 A1 A2 A3");
	Student* st2 = new Student("2 B1 B2 B3");
	Student* st3 = new Student("3 C1 C2 C3");
	gr->add_student(st1);
	gr->add_student(st2);
	gr->add_student(st3);
	EXPECT_EQ(st1, gr->search_student(1));
	EXPECT_EQ(st2, gr->search_student("B1 B2 B3"));
}







