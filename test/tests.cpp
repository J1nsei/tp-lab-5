#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Dean.h"

TEST(testStudent, middle_mark)
{
	Student* student = new Student(10,"Alex Petrov", "1");
	
		student->AddMark(1);
		student->AddMark(2);
		student->AddMark(3);
		student->AddMark(4);
	
	EXPECT_EQ(2.5, student->MiddleMark());
	
}

TEST(testGroup, middle_mark)
{
	Group* group1 = new Group("1");
	Student* student1 = new Student(10, "Alex Petrov", "1");
	Student* student2 = new Student(11, "Alex Karpov", "1");

	student1->AddMark(1);
	student1->AddMark(2);
	student1->AddMark(3);
	student1->AddMark(4);
	student2->AddMark(1);
	student2->AddMark(2);
	student2->AddMark(3);
	student2->AddMark(4);
	group1->AddStudent(student1);
	group1->AddStudent(student2);

	EXPECT_EQ(2.5, group1->MiddleGroupMark());

}
