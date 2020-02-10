#include "gtest/gtest.h"
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

// task1
TEST(lab5, task1_1)
{
	Student S = Student(0, "Тусик Карпий Андросович");
	EXPECT_EQ(0, S.get_id());
	Group G = Group("20ПМИ-1");
	S.change_group(&G);
	EXPECT_EQ(&G, S.get_group());
}
TEST(lab5, task1_2)
{
	Student S = Student(0, "Тусик Карпий Андросович");
	S.set_mark(5);
	S.set_mark(5);
	S.set_mark(5);
	S.set_mark(5);
	EXPECT_EQ(5.0, S.average_mark());
}

TEST(lab5, task1_3)
{
	Student S = Student(0, "Тусик Карпий Андросович");
	EXPECT_EQ("Тусик Карпий Андросович", S.get_fio());
}
TEST(lab5, task1_4)
{
	Student S_1 = Student(0, "Тусик Карпий Андросович");
	Student S_2 = Student(1, "Лем Оанн Рыбович");
	Group G = Group("20ПМИ-1");
	G.add_student_(&S_1);
	G.add_student_(&S_2);
	EXPECT_EQ(1, G.student_in_group(1));
	EXPECT_EQ(1, G.student_in_group("Лем Оанн Рыбович"));
}
TEST(lab5, task1_5)
{
	Student S_1 = Student(0, "Тусик Карпий Андросович");
	Student S_2 = Student(1, "Лем Оанн Рыбович");
	S_1.set_mark(8);
	S_1.set_mark(7);
	S_2.set_mark(6);
	S_2.set_mark(5);
	Group G = Group("20ПМИ-1");
	EXPECT_EQ("Нету", G.get_head());
	G.add_student_(&S_1);
	G.add_student_(&S_2);
	G.choose_head();
	EXPECT_EQ("Тусик Карпий Андросович", G.get_head());
}
TEST(lab5, task1_6)
{
	Deanery* D = new Deanery("students.txt");
	Student* S_1 = new Student(1000, "Тусик Карпий Андросович");
	Student* S_2 = new Student(1001, "Лем Оанн Рыбович");
	Student* S_3 = new Student(1002, "Кравт Данте Дионисович");
	Group* G_1 = D->make_group("20-1");
	Group* G_2 = D->make_group("20-2");
	D->add_group(G_1);
	D->add_group(G_2);
	D->add_student(G_1, S_1);
	D->add_student(G_1, S_2);
	D->add_student(G_2, S_3);
	EXPECT_EQ(1, G_1->student_in_group(1000));
	EXPECT_EQ(1, D->transmit_student(G_2, 1000));
	EXPECT_EQ(0, D->transmit_student(G_1, G_2, 1000));
}
TEST(lab5, task1_7)
{
	Deanery* D = new Deanery("students.txt");
	D->add_marks();
	Student* S_1 = new Student(1000, "Тусик Карпий Андросович");
	Student* S_2 = new Student(1001, "Лем Оанн Рыбович");
	Student* S_3 = new Student(1002, "Кравт Данте Дионисович");
	D->add_mark("Тусик Карпий Андросович", 10);
	Group* G_1 = D->make_group("20-1");
	Group* G_2 = D->make_group("20-2");
	D->add_group(G_1);
	D->add_group(G_2);
	D->add_student(G_1, S_1);
	D->add_student(G_1, S_2);
	D->add_student(G_2, S_3);

	EXPECT_EQ(0, D->get_average_mark_student(1000));

	D->add_mark("Тусик Карпий Андросович", 10);
	D->add_mark(1000, 9);
	D->add_mark("Лем Оанн Рыбович", 5);
	D->add_mark(1001, 4);
	
	EXPECT_EQ(9, D->get_average_mark_student("Тусик Карпий Андросович"));
	EXPECT_EQ(4, D->get_average_mark_student("Лем Оанн Рыбович"));
	EXPECT_EQ(0, D->get_average_mark_student(1002));
}
TEST(lab5, task1_8)
{
	Deanery* D = new Deanery("students.txt");
	D->add_marks();
	Student* S_1 = new Student(1000, "Тусик Карпий Андросович");
	Student* S_2 = new Student(1001, "Лем Оанн Рыбович");
	Student* S_3 = new Student(1002, "Кравт Данте Дионисович");
	Group* G_1 = D->make_group("20-1");
	Group* G_2 = D->make_group("20-2");
	D->add_group(G_1);
	D->add_group(G_2);
	D->add_student(G_1, S_1);
	D->add_student(G_1, S_2);
	D->add_student(G_2, S_3);
	D->find_student(1002)->change_group(G_1);
	EXPECT_EQ("Ошибка в указателе группы у студента: Кравт Данте Дионисович", D->small_check());
	D->find_student(1002)->change_group(D->find_student_in_group(1002));
	EXPECT_EQ("Теперь все норм", D->small_check());
}
