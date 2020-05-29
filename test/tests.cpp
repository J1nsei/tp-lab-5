#include "gtest/gtest.h"
#include "Dean.h"
#include "Group.h"
#include "Student.h"

TEST(lab5, test1)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	for (int i = 0; i < 5; i++) {
		IMIKN.addMarkToStudent("Ivanov Ivan", "18PMI-1", 10);
		IMIKN.addMarkToStudent("Petrov Petr", "18PMI-1", 5);
		IMIKN.addMarkToStudent("Vasiliev Vasiliy", "18PMI-1", 0);
	}
	EXPECT_EQ(IMIKN.expelStudentsByAverageMark(4), 1);
}
TEST(lab5, test2)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.createGroup("18PMI-2", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	EXPECT_EQ(IMIKN.trasferStudentToNewGroup("Ivanov Ivan", "18PMI-1", "18PMI-2")->getGroupName(), "18PMI-2");
}
TEST(lab5, test3)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	for (int i = 0; i < 5; i++) {
		IMIKN.addMarkToStudent("Ivanov Ivan", "18PMI-1", 10);
		IMIKN.addMarkToStudent("Petrov Petr", "18PMI-1", 5);
		IMIKN.addMarkToStudent("Vasiliev Vasiliy", "18PMI-1", 0);
	}
	EXPECT_EQ(IMIKN.getAverageMarkInGroup("18PMI-1"), 5);
}

TEST(lab5, test4)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	for (int i = 0; i < 5; i++) {
		IMIKN.addMarkToStudent("Ivanov Ivan", "18PMI-1", 10);
		IMIKN.addMarkToStudent("Petrov Petr", "18PMI-1", 5);
		IMIKN.addMarkToStudent("Vasiliev Vasiliy", "18PMI-1", 0);
	}
	EXPECT_EQ(IMIKN.getAverageMarkOfStudent("Petrov Petr", "18PMI-1"), 5);
}

TEST(lab5, test5)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	EXPECT_EQ(IMIKN.searchGroupByName("18PMI-1")->getGroupName(), "18PMI-1");
}

TEST(lab5, test6)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	EXPECT_EQ(IMIKN.getNumberOfStudentsInGroup("18PMI-1"), 3);
}

TEST(lab5, test7)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	for (int i = 0; i < 5; i++) {
		IMIKN.addMarkToStudent("Ivanov Ivan", "18PMI-1", 10);
		IMIKN.addMarkToStudent("Petrov Petr", "18PMI-1", 5);
		IMIKN.addMarkToStudent("Vasiliev Vasiliy", "18PMI-1", 0);
	}
	IMIKN.expelStudentsByAverageMark(4);
	EXPECT_EQ(IMIKN.getNumberOfStudentsInGroup("18PMI-1"), 2);
}

TEST(lab5, test8)
{
	Dean IMIKN{ "IMIKN" };
	IMIKN.createGroup("18PMI-1", "Engineering");
	IMIKN.createGroup("18PMI-2", "Engineering");
	IMIKN.addStudentToGroup("Ivanov Ivan", "18PMI-1");
	IMIKN.addStudentToGroup("Petrov Petr", "18PMI-1");
	IMIKN.addStudentToGroup("Vasiliev Vasiliy", "18PMI-1");
	IMIKN.trasferStudentToNewGroup("Ivanov Ivan", "18PMI-1", "18PMI-2");
	EXPECT_EQ(IMIKN.getNumberOfStudentsInGroup("18PMI-1"), 2);
}



