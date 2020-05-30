#include "gtest/gtest.h"
#include "Group.h"

TEST (testStudent, getFIO)
{
    Student student(0, "Саратовцев Артем Романович");
    EXPECT_EQ("Саратовцев Артем Романович", student.getFIO());
}

TEST (testStudent, getID)
{
    Student student(0, "Саратовцев Артем Романович");
    EXPECT_EQ(0, student.getID());
}

TEST (testStudent, addMark)
{
    Student student(0, "Саратовцев Артем Романович");
    student.addMark(5);
    EXPECT_EQ(5, student.calcMean());
}

TEST (testStudent, enroll)
{
    Student student(0, "Саратовцев Артем Романович");
    Group* group = new Group("18PI-1", "Satanizm");
    student.enroll(group);
    EXPECT_EQ(group, student.getGroup());
}

TEST (testGroup, getTitle)
{
    Student* student = new Student(0, "Саратовцев Артем Романович");
    Group* group = new Group("18PI-1", "Satanizm");
    student->enroll(group);
    EXPECT_EQ("18PI-1", group->getTitle());
}

TEST (testGroup, addStudent)
{
    Student* student = new Student(0, "Саратовцев Артем Романович");
    Group* group = new Group("18PI-1", "Satanizm");
    student->enroll(group);
    group->addStudent(student);
    EXPECT_EQ("Саратовцев Артем Романович", group->getStudents()[0]->getFIO());
}

