#include "gtest/gtest.h"
#include "deanery.h"
#include "student.h"
#include "group.h"

TEST(task1, case_1) 
{
    Student* student = new Student("Polina Demochkina");
    student->addMark(2);
    student->addMark(10);
    EXPECT_EQ((int)student->getAverage(), 6);
}


TEST(task1, case_2) 
{
    Group* group = new Group("18PI-1");
    Student* student1 = new Student("Polina Demochkina");
    Student* student2 = new Student("Dmitry Tereshin");

    student1->addToGroup(group);
    student2->addToGroup(group);

    student1->addMark(4);
    student1->addMark(2);
    student2->addMark(8);
    student2->addMark(10);

    EXPECT_EQ((int)group->getGroupAverage(), 6);
}


TEST(task1, case_3) {
    Group* group = new Group("18PI-1");
    Student* student = new Student("Polina Demochkina");

    student->addToGroup(group);

    group->selectHead(student);

    EXPECT_EQ(group->getHead(), student);
}


TEST(task1, case_4) {
    Group* group = new Group("18PI-1");
    Student* student = new Student("Polina Demochkina");

    student->addToGroup(group);

    EXPECT_EQ(group->search("Polina Demochkina"), student);
}


TEST(task1, case_5) {
    Group* group = new Group("18PI-1");
    Student* student = new Student("Polina Demochkina");

    student->addToGroup(group);

    EXPECT_EQ(student->getGroup(), group);
}


TEST(task1, case_6) {
    Group* group = new Group("18PI-1");

    EXPECT_EQ(group->getTitle(), "18PI-1");
}


TEST(task1, case_7) {
    Student* student = new Student("Mikhail Zhelezin");

    student->addMark(8);
    student->addMark(1);

    EXPECT_EQ(student->getMarksForWrite(), "81");
}