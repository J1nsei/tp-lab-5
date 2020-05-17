#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"

TEST(student_test, testFIO) {
 	Student* student = new Student(101, "Мартынюк Олеся Олеговна");
 	EXPECT_EQ("Мартынюк Олеся Олеговна", student->getFIO());
 }

 TEST(student_test, testID) {
 	Student* student = new Student(101, "Мартынюк Олеся Олеговна");
 	EXPECT_EQ(101, student->getID());
 }

 TEST(student_test, testSpec) {
 	Group* group = new Group("18ПИ2", "Программирование");
 	Student* student = new Student(101, "Мартынюк Олеся Олеговна");
 	student->addToGroup(group);
 	group->addStudent(student);
 	EXPECT_EQ("Программирование", student->getGroup()->getSpec());
 }

 TEST(group_test, testMove) {
 	Deanery* deanery = new Deanery();
 	Group* group1 = new Group("18ПИ1", "Программирование");
 	deanery->groups.push_back(group1);
 	Student* student = new Student(101, "Мартынюк Олеся Олеговна");
 	student->addToGroup(group1);
 	group1->addStudent(student);
 	EXPECT_EQ("18ПИ1", student->getGroup()->getTitle());
 	Group* group2 = new Group("18ПИ2", "Программирование");
 	deanery->groups.push_back(group2);
 	deanery->moveStudent("Мартынюк Олеся Олеговна", "18ПИ2");
 	EXPECT_EQ("18ПИ2", student->getGroup()->getTitle());;
 }


 TEST(group_test, testHead) {
 	Deanery* deanery = new Deanery();
 	deanery->groups.push_back(group);
 	Group* group = new Group("18ПИ2", "Программирование");
 	Student* student = new Student(101, "Мартынюк Олеся Олеговна");
 	student->addToGroup(group);
 	group->addStudent(student);
 	deanery->electHead();
 	EXPECT_EQ(101, deanry->getGroup()->getHead()->getID());
 }


