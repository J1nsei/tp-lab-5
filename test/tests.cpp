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
