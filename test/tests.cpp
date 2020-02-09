#include "gtest/gtest.h"
#include "dean.h"
#include "student.h"
#include "group.h"

TEST(task1, case_1) {
    Student* student = new Student(0, "Mikhail Zhelezin");
    student->addMark(8);
    student->addMark(10);
    EXPECT_EQ((int)student->calcAverageMark(), 9);
}


TEST(task1, case_2) {
    Group* PI_1 = new Group("18PI-1", "Software engineering");
    Student* student_1 = new Student(0, "Mikhail Zhelezin");
    Student* student_2 = new Student(1, "Maria Krylova");

    student_1->addMark(8);
    student_1->addMark(6);
    student_2->addMark(8);
    student_2->addMark(10);

    student_1->addToGroup(PI_1);
    student_2->addToGroup(PI_1);

    PI_1->addStudent(student_1);
    PI_1->addStudent(student_2);

    EXPECT_EQ((int)PI_1->calcAverageMark(), 8);
}


TEST(task1, case_3) {
    Group* PI_1 = new Group("18PI-1", "Software engineering");
    Student* student_1 = new Student(0, "Mikhail Zhelezin");
    Student* student_2 = new Student(1, "Maria Krylova");

    student_1->addMark(8);
    student_1->addMark(6);
    student_2->addMark(8);
    student_2->addMark(10);

    student_1->addToGroup(PI_1);
    student_2->addToGroup(PI_1);

    PI_1->addStudent(student_1);
    PI_1->addStudent(student_2);

    PI_1->addHead(student_1);

    EXPECT_EQ(PI_1->getHead(), student_1);
}


TEST(task1, case_4) {
    Group* PI_1 = new Group("18PI-1", "Software engineering");
    Student* student_1 = new Student(0, "Mikhail Zhelezin");
    Student* student_2 = new Student(1, "Maria Krylova");

    student_1->addMark(8);
    student_1->addMark(6);
    student_2->addMark(8);
    student_2->addMark(10);

    student_1->addToGroup(PI_1);
    student_2->addToGroup(PI_1);

    PI_1->addStudent(student_1);
    PI_1->addStudent(student_2);

    PI_1->excludeStudent(student_1)

    EXPECT_EQ(PI_1->getStudents().size(), 1);
}


TEST(task1, case_4) {
    Group* PI_1 = new Group("18PI-1", "Software engineering");
    Student* student_1 = new Student(0, "Mikhail Zhelezin");
    Student* student_2 = new Student(1, "Maria Krylova");

    student_1->addMark(8);
    student_1->addMark(6);
    student_2->addMark(8);
    student_2->addMark(10);

    student_1->addToGroup(PI_1);
    student_2->addToGroup(PI_1);

    PI_1->addStudent(student_1);
    PI_1->addStudent(student_2);

    EXPECT_EQ(PI_1->findFio("Maria Krylova"), student_2);
}
