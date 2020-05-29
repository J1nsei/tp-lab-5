#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>


TEST(testGroup, avr_mark) {
	Student student1(1, "Paola Moka");
	Student student2(2, "John J");
	Group group("18pmi-1");
	group.AddStudent(&student1);
	group.AddStudent(&student2);
	for (int i = 0; i < 10; i++) {
		student1.AddMark(i);
		student2.AddMark(2*i);
	}
	EXPECT_EQ(6.75, group.AverageGroup());
}

TEST(testStudent, avg_mark) {
	Student student(1, "Paola Moka");
	for (int i = 0; i < 10; i++) 
	{
		student.AddMark(i);
	}
	EXPECT_EQ(4.5, student.AverageBall());
}

TEST(testGroup, size) {
	Group group("18pmi-1");
	Student student(1, "Paola Moka");
	group.AddStudent(&student);
	EXPECT_EQ(1, group.GetSize());
}

/*
TEST(testDean, expel) {
	std::string filename = "students1.txt";
	Dean dean(filename);
	EXPECT_EQ("17?-2", dean.find_group("17?-2")->find_student("Oa?iai Iienae Oeuyiiae?")->get_group());
	dean.find_group("17?-2")->expel_student("Oa?iai Iienae Oeuyiiae?");
	EXPECT_EQ(nullptr, dean.find_group("17?-2")->find_student("Oa?iai Iienae Oeuyiiae?"));
}
TEST(testDean, transfer) {
	std::string filename = "students1.txt";
	Dean dean(filename);
	dean.student_transfer("Ia?aaa Eaa? Oeio?iae?", "17?-2", "19IE-1");
	Group *groupU = dean.find_group("17?-2");
	Group *groupPI = dean.find_group("19IE-1");
	EXPECT_EQ(nullptr, groupU->find_student("Ia?aaa Eaa? Oeio?iae?"));
	EXPECT_EQ("Ia?aaa Eaa? Oeio?iae?", groupPI->find_student(groupPI->get_size() - 1)->get_name());
} */