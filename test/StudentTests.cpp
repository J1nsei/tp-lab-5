#include <cstdlib>
#include "gtest/gtest.h"
#include "Student.h"

TEST(StudentTests, AddGradeTest)
{
    std::vector<int8_t> grades { 1, 2, 3, 4, 5 };
    Student student(0, "First Name", "Last Name", std::vector<int8_t> { 1, 2, 3, 4, 5 });

    grades.push_back(5);
    student.AddGrade(5);

    EXPECT_EQ(grades.size(), student.GetGrades()->size());
    for (uint32_t i = 0; i < student.GetGrades()->size(); i++)
        EXPECT_EQ(grades[i], (*student.GetGrades())[i]);
}

TEST(StudentTests, RemoveGradeTest)
{
    std::vector<int8_t> grades { 1, 2, 3, 4, 5 };
    Student student(0, "First Name", "Last Name", std::vector<int8_t> { 1, 2, 3, 4, 5 });

    grades.erase(grades.begin() + 4);
    student.RemoveGrade(5);

    EXPECT_EQ(grades.size(), student.GetGrades()->size());
    for (uint32_t i = 0; i < student.GetGrades()->size(); i++)
        EXPECT_EQ(grades[i], (*student.GetGrades())[i]);
}

TEST(StudentTests, CalculateAverageGradeTest)
{
    std::vector<int8_t> grades { 1, 2, 3, 4, 5 };
    Student student(0, "First Name", "Last Name", std::vector<int8_t> { 1, 2, 3, 4, 5 });

    float averageGradeExpected = 0;
    for (uint32_t i = 0; i < grades.size(); i++)
        averageGradeExpected += grades[i];
    averageGradeExpected /= grades.size();
    float averageGradeActual = student.CalculateAverageGrade();

    EXPECT_TRUE(abs(averageGradeExpected - averageGradeActual) < 0.01);
}
