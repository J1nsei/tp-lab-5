#include <cstdlib>
#include "gtest/gtest.h"
#include "Group.h"
#include "Student.h"

TEST(GroupTests, AddStudentTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    Student *studentToAdd = new Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 });
    Group group("Title", "Specialization", students, students[0]);

    group.AddStudent(studentToAdd);

    EXPECT_EQ(3, group.GetStudents()->size());
    EXPECT_EQ(0, (*group.GetStudents())[0]->GetId());
    EXPECT_EQ(1, (*group.GetStudents())[1]->GetId());
    EXPECT_EQ(2, (*group.GetStudents())[2]->GetId());

    for (uint32_t i = 0; i < students.size(); i++)
        delete students[i];
    delete studentToAdd;
}

TEST(GroupTests, RemoveStudentTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    Group group("Title", "Specialization", students, students[0]);

    group.RemoveStudent((*group.GetStudents())[1]);

    EXPECT_EQ(1, group.GetStudents()->size());
    EXPECT_EQ(0, (*group.GetStudents())[0]->GetId());

    for (uint32_t i = 0; i < students.size(); i++)
        delete students[i];
}

TEST(GroupTests, GetStudentByIdTest)
{
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    Group group("Title", "Specialization", std::vector<Student *> { &(students[0]), &(students[1]), &(students[2]), &(students[3]) }, &(students[0]));

    EXPECT_EQ(&students[2], group.GetStudentById(2));
}

TEST(GroupTests, GetStudentByNameTest)
{
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    Group group("Title", "Specialization", std::vector<Student *> { &(students[0]), &(students[1]), &(students[2]), &(students[3]) }, &(students[0]));

    EXPECT_EQ(&(students[1]), group.GetStudentByName("Declan", "Lewis"));
}

TEST(GroupTests, CalculateAverageGradeTest)
{
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    Group group("Title", "Specialization", std::vector<Student *> { &(students[0]), &(students[1]), &(students[2]), &(students[3]) }, &(students[0]));

    float averageGradeExpected = 0;
    uint32_t gradesCount = 0;
    for (uint32_t i = 0; i < group.GetStudents()->size(); i++)
    {
        for (uint32_t j = 0; j < (*group.GetStudents())[i]->GetGrades()->size(); j++)
        {
            averageGradeExpected += (*(*group.GetStudents())[i]->GetGrades())[j];
            gradesCount++;
        }
    }
    averageGradeExpected /= gradesCount;
    float averageGradeActual = group.CalculateAverageGrade();

    EXPECT_TRUE(abs(averageGradeExpected - averageGradeActual) < 0.01);
}
