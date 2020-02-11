#include "gtest/gtest.h"
#include "Dean.h"
#include "Group.h"
#include "Student.h"
#include <locale.h>

TEST(tplab5, test1)
{
	setlocale(LC_ALL, "Russian");
	Dean imikn("imikn");
	imikn.create_group("18ПМИ-1", "Программирование");
	imikn.add_student_to_group("Воронов Пётр Алексеевич", "18ПМИ-1");
	imikn.add_student_to_group("Петров Пётр Евгеньевич", "18ПМИ-1");
	imikn.add_student_to_group("Яковлев Андрей Михайлович", "18ПМИ-1");
	imikn.add_student_to_group("Шубин Константин Алексеевич", "18ПМИ-1");
	Group* pmi18_1 = imikn.search_group_name("18ПМИ-1");
	int full = 0;
	for (int i = 0; i < 8; i++) {
		switch (i % 4) {
		case 0:
			imikn.add_mark_to_student(pmi18_1->get_title(), "Воронов Пётр Алексеевич", 2 * (i + 1)); // 2, 10 // avg = 6
			break;
		case 1:
			imikn.add_mark_to_student(pmi18_1->get_title(), "Петров Пётр Евгеньевич", i + 5); // 6, 10 // avg = 8
			break;
		case 2:
			imikn.add_mark_to_student(pmi18_1->get_title(), "Яковлев Андрей Михайлович", 2 * i - 3); // 1, 9 // avg = 5
			break;
		case 3:
			imikn.add_mark_to_student(pmi18_1->get_title(), "Шубин Константин Алексеевич", 10); // 10, 10 // avg = 10
			break;
		}
	}

	EXPECT_EQ(pmi18_1->average_score(), 7.25);
}

TEST(tplab5, test2)
{
	setlocale(LC_ALL, "Russian");
	Dean imikn("imikn");
	imikn.create_group("18ПМИ-1", "Программирование");
	imikn.create_group("18ПИ-1", "Инженерия");
	imikn.add_student_to_group("Воронов Пётр Алексеевич", "18ПМИ-1");
	imikn.add_student_to_group("Петров Пётр Евгеньевич", "18ПИ-1");
	imikn.add_student_to_group("Яковлев Андрей Михайлович", "18ПИ-1");
	imikn.add_student_to_group("Шубин Константин Алексеевич", "18ПМИ-1");

	imikn.move_students("Петров Пётр Евгеньевич", "18ПИ-1", "18ПМИ-1");
	
	Group* pmi18_1 = imikn.search_group_name("18ПМИ-1");
	Student stud_for_check = pmi18_1->search_student_name("Петров Пётр Евгеньевич");
	EXPECT_NE(stud_for_check.getId(), 0);
}
