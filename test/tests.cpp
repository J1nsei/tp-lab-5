#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST(testGroup, averageMark) 
{
	Student student1(1, "Logan Antonio Hughes");
	Student student2(2, "Cameron Elijah Bennett");
	Student student3(3, "Wyatt Isaiah Ramirez");
	Group group("18PI");

	group.addStudent(&student1);
	group.addStudent(&student2);
	group.addStudent(&student3);

	for (int i = 0; i < 9; i++) 
	{
		student1.setMarks(i);
		student2.setMarks(i + 1);
		student3.setMarks(i + 2);
	}
	EXPECT_EQ(5, group.averageMarkGroup());
}

TEST(testGroup, size) 
{
	Student student1(1, "Miguel Ashton Green");
	Student student2(2, "William Lawson Spiced");
	Student student3(3, "Philip Joshua Morris");
	Group group("18BI");

	group.addStudent(&student1);
	group.addStudent(&student2);
	group.addStudent(&student3);

	EXPECT_EQ(3, group.studSize());
}

TEST(testStudent, getID)
{
	Student student(1, "Nick Adam Turner");
	EXPECT_EQ(1, student.getID());
}

TEST(testStudent, getFIO)
{
	Student student(99, "Sarah Catherine Paulson");
	EXPECT_EQ("Sarah Catherine Paulson", student.getFIO());
}

TEST(testStudent, avMark) 
{
	Student student(1, "Albus Wulfric Dumbledore");

	for (int i = 0; i < 5; i++)
	{
		student.setMarks(i * 2 + 2);
	}
	student.setMarks(3);

	EXPECT_EQ(5.5, student.getAvarageMarks());
}