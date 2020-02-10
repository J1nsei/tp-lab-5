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
    student.setMarks(5);
    EXPECT_EQ(5, student.getAverageMarks());
}

TEST (testGroup, enroll)
{
    Student student(0, "Саратовцев Артем Романович");
    Group* group = new Group("18PI-1", "Satanizm");
    student.enroll(group);
    EXPECT_EQ(group, student.getGroup());
}


