#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

TEST(lab5, task1)	//done
{
	Student Pasha(0, "Паша Зайцев");
	Pasha.deleteMarks();
	Pasha.addMark(5);
	Pasha.addMark(6);
	Pasha.addMark(7);
	Pasha.addMark(8);
	EXPECT_EQ(6.5, Pasha.averageMark());
}

TEST(lab5, task2)	//done
{
	Student Pasha(0, "Паша Зайцев");
	EXPECT_EQ(0, Pasha.getId());
}

TEST(lab5, task3)	//done
{
	Student Pasha(0, "Паша Зайцев");
	EXPECT_EQ("Паша Зайцев", Pasha.getFIO());
}

TEST(lab5, task4)	//done
{
	Group testGroup("testGroup");
	EXPECT_EQ("testGroup", testGroup.getTitle());
}

TEST(lab5, task5)
{
	Group testGroup("testGroup");
	Student* first = new Student("Паша Зайцев");
	Student* second = new Student("Маша Лисичкина");
	first->addMark(5);
	first->addMark(6);
	second->addMark(7);
	second->addMark(8);
	testGroup.recieveStudent(first);
	testGroup.recieveStudent(second);

	EXPECT_EQ(6.5, testGroup.averageGroupMark());
}

TEST(lab5, task6)
{
	Group testGroup("testGroup");
	Student* first = new Student("Паша Зайцев");
	Student* second = new Student("Маша Лисичкина");
	first->addMark(5);
	first->addMark(6);
	second->addMark(7);
	second->addMark(8);
	testGroup.recieveStudent(first);
	testGroup.recieveStudent(second);
	Student* _tmp;
	_tmp = testGroup.headChoice();
	EXPECT_EQ("Маша Лисичкина", _tmp->getFIO());
}

TEST(lab5, task7)
{
	Group testGroup("testGroup");
	Student* first = new Student("Паша Зайцев");
	Student* second = new Student("Маша Лисичкина");
	first->addMark(5);
	first->addMark(6);
	second->addMark(7);
	second->addMark(8);

	testGroup.recieveStudent(first);
	testGroup.recieveStudent(second);
	testGroup.addRandomMarks();
	EXPECT_EQ(false, testGroup.averageGroupMark() == 6.5);
}