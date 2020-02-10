#include "gtest/gtest.h"
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include <string>

TEST (testGroup, averageMark) 
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