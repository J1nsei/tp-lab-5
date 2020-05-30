#include "gtest/gtest.h"
#include "dean.h"
#include "group.h"
#include "student.h"
#include <string>

TEST (testStudent, getFIO)
{
    Student student(0, "Иванов Иван Иванович");
    EXPECT_EQ("Иванов Иван Иванович", student.getFIO());
}

TEST (testStudent, getID)
{
    Student student(0, "Иванов Иван Иванович");
    EXPECT_EQ(0, student.getID());
}

TEST (testStudent, getAverageMarks)
{
    Student student(0, "Иванов Иван Иванович");
    student.setMarks(5);
    EXPECT_EQ(5, student.getAverageMarks());
}

TEST (testGroup, getGroupSize)
{
    Student student(0, "Иванов Иван Иванович");
    Group group("PI");
    group.addStudent(&student);
    EXPECT_EQ(1, group.getGroupSize());
}




