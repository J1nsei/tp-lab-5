#include "gtest/gtest.h"
#include "Dean.h"
#include "Student.h"
#include "Group.h"
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

TEST(testDean, init) {
	std::string filename = "students1.txt";
	Dean dean(filename);

	dean.find_group("17Ю-2")->set_spec("Юрисприденция");
	dean.find_group("18ПМИ-2")->set_spec("Прикладная математика и информатика");
	dean.find_group("19ПИ-1")->set_spec("Программирование");

	EXPECT_EQ(13, dean.find_group("17Ю-2")->get_size());
	EXPECT_EQ(nullptr, dean.find_group("17-2"));
}

TEST(testDean, expel) {
	std::string filename = "students1.txt";
	Dean dean(filename);

	EXPECT_EQ("17Ю-2", dean.find_group("17Ю-2")->find_student("Херман Моисей Ульянович")->get_group());

	dean.find_group("17Ю-2")->expel_student("Херман Моисей Ульянович");

	EXPECT_EQ(nullptr, dean.find_group("17Ю-2")->find_student("Херман Моисей Ульянович"));
}

TEST(testDean, transfer) {
	std::string filename = "students1.txt";
	Dean dean(filename);

	dean.student_transfer("Нечаев Лавр Тимурович", "17Ю-2", "19ПИ-1");
	Group *groupU = dean.find_group("17Ю-2");
	Group *groupPI = dean.find_group("19ПИ-1");

	EXPECT_EQ(nullptr, groupU->find_student("Нечаев Лавр Тимурович"));
	EXPECT_EQ("Нечаев Лавр Тимурович", groupPI->find_student(groupPI->get_size() - 1)->get_name());
} 