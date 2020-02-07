#include "gtest/gtest.h"
#include "Deanery.h"

TEST(student, get_fio)
{
	Student* stud = new Student(0, "FIO of student");
	string FIO = stud->get_fio();
	EXPECT_EQ("FIO of student", FIO);
}

TEST(student, get_id)
{
	Student* stud = new Student(0, "FIO of student");
	int id = stud->get_id();
	EXPECT_EQ(0, id);
}

TEST(student, check_marks)
{
	Student* stud = new Student(0, "FIO of student");
	stud->set_mark(1);
	stud->set_mark(5);
	stud->set_mark(10);
	vector<int> marks = stud->get_marks();
	vector<int> expected_marks = { 1, 5, 10 };
	EXPECT_EQ(marks, expected_marks);
}

TEST(student, check_group)
{
	Group * gr = new Group("group_title", "group_specialization");
	Student* stud = new Student(0, "FIO of student");
	stud->set_group(gr);
	Group* get_gr = stud->get_group();
	EXPECT_EQ(gr, get_gr);
}

TEST(student, average_mark)
{
	Student* stud = new Student(0, "FIO of student");
	stud->set_mark(5);
	stud->set_mark(10);
	float mark = stud->average_mark();
	EXPECT_EQ(7.5, mark);
}

TEST(group, title)
{
	Group* gr = new Group("group_title", "group_specialization");
	string title = gr->get_title();
	EXPECT_EQ("group_title", title);
}

TEST(group, specialization)
{
	Group* gr = new Group("group_title", "group_specialization");
	string spec = gr->get_spec();
	EXPECT_EQ("group_specialization", spec);
}

TEST(group, head)
{
	Group* gr = new Group("group_title", "group_specialization");
	Student* stud = new Student(0, "FIO of student");
	gr->add_student(stud);
	gr->election_head();
	Student* head = gr->get_head();
	EXPECT_EQ(stud, head);
}

TEST(group, average_mark)
{
	Group* gr = new Group("group_title", "group_specialization");
	Student* stud1 = new Student(0, "FIO of student 1");
	Student* stud2 = new Student(1, "FIO of student 2");
	gr->add_student(stud1);
	gr->add_student(stud2);
	stud1->set_mark(5);
	stud2->set_mark(10);
	float mark = gr->average_mark();
	EXPECT_EQ(7.5, mark);
}

TEST(group, find_by_fio)
{
	Group* gr = new Group("group_title", "group_specialization");
	Student* stud = new Student(0, "FIO of student");
	gr->add_student(stud);
	Student * st = gr->find_student_fio("FIO of student");
	EXPECT_EQ(st, stud);
}

TEST(group, find_by_id)
{
	Group* gr = new Group("group_title", "group_specialization");
	Student* stud = new Student(0, "FIO of student");
	gr->add_student(stud);
	Student* st = gr->find_student_id(0);
	EXPECT_EQ(st, stud);
}

TEST(deanery, marks)
{
	Deanery dean;
	Group* gr = dean.make_group("group_title", "group_specialization");
	dean.make_student(0, "FIO of student", gr);
	dean.add_mark(gr, "FIO of student", 0);
	dean.poor_grades(gr);
	int number_of_stud = (gr->get_students()).size();
	EXPECT_EQ(number_of_stud, 0);
}

TEST(deanery, head)
{
	Deanery dean;
	Group* gr = dean.make_group("group_title", "group_specialization");
	dean.make_student(0, "FIO of student", gr);
	dean.make_head(gr);
	Student * head = gr->get_head();
	Student* expected = gr->get_students()[0];
	EXPECT_EQ(head, expected);
}

TEST(deanery, change_group)
{
	Deanery dean;
	Group* gr1 = dean.make_group("group_title_1", "group_specialization_1");
	Group* gr2 = dean.make_group("group_title_2", "group_specialization_2");
	dean.make_student(0, "FIO of student", gr1);
	dean.change_group_for_student("FIO of student", gr1, gr2);
	string FIO = (gr2->get_students()[0])->get_fio();	
	EXPECT_EQ(FIO, "FIO of student");
}

TEST(deanery, average_mark_for_group)
{
	Deanery dean;
	Group* gr = dean.make_group("group_title", "group_specialization");
	dean.make_student(0, "FIO of student_1", gr);
	dean.make_student(1, "FIO of student_2", gr);
	dean.add_mark(gr, "FIO of student_1", 10);
	dean.add_mark(gr, "FIO of student_1", 9);
	dean.add_mark(gr, "FIO of student_1", 5);
	dean.add_mark(gr, "FIO of student_2", 4);
	float mark = dean.get_average_mark_group(gr);
	EXPECT_EQ(6, mark);
}

TEST(deanery, average_mark_for_student)
{
	Deanery dean;
	Group* gr = dean.make_group("group_title", "group_specialization");
	dean.make_student(0, "FIO of student", gr);
	dean.add_mark(gr, "FIO of student", 5);
	dean.add_mark(gr, "FIO of student", 10);
	float mark = dean.get_average_mark_student(gr, "FIO of student");
	EXPECT_EQ(7.5, mark);
}