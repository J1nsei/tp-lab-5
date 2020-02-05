#include "gtest/gtest.h"
#include <dean.h>

TEST(DeaneryDemo, dean_1) {
    Dean* dean = new Dean();
    EXPECT_EQ(100, dean->getStudents().size());
    delete dean;
}

TEST(DeaneryDemo, dean_2) {
    Dean* dean = new Dean();
    EXPECT_EQ(4, dean->getGroups().size());
    delete dean;
}

TEST(DeaneryDemo, dean_3) {
    Student* student = new Student(1, "Артем Валерьевич Батков");
    student->addMark(3);
    EXPECT_EQ(1, student->getMarks().size());
    delete student;
}

TEST(DeaneryDemo, dean_4) {
    Student* student = new Student(1, "Артем Валерьевич Батков");
    student->addMark(3);
    EXPECT_EQ(3, student->getMean());
    delete student;
}

TEST(DeaneryDemo, dean_5) {
    Group* group = new Group("19PI", "SE");
    EXPECT_EQ("19PI", group->getTitle());
    delete group;
}