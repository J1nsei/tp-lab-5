#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

TEST(testStudent, test1) {
    Student* student = new Student(1, "Maxim Maximov");

    student->addMark(5);
    student->addMark(5);
    student->addMark(3);
    student->addMark(3);

    EXPECT_EQ(4, student->averageMark());

}

TEST(testGroup, test2) {
    Group* group1 = new Group("1");
    Student* student1 = new Student(2, "Maxim Maximov");
    Student* student2 = new Student(3, "Ivan Ivanov");

    student1->addMark(5);
    student1->addMark(4);
    student1->addMark(5);
    student1->addMark(3);
    student2->addMark(4);
    student2->addMark(4);
    student2->addMark(3);
    group1->AddStudent(student1);
    group1->AddStudent(student2);

    EXPECT_EQ(4, group1->averageMark());

}
