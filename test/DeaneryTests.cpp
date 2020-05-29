#include <sstream>
#include "gtest/gtest.h"
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

TEST(DeaneryTests, LogStatisticsTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    std::vector<Group *> groups
    {
        new Group("Title", "Specialization", students, students[0])
    };

    std::ostringstream streamWriter;
    DeaneryLogger deaneryLogger(&streamWriter);
    Deanery deanery(&deaneryLogger, &students, &groups);
    deanery.LogStatistics();

    EXPECT_EQ(std::string("Student Id: 0") + "\n"
        + std::string("First Name: Rory") + "\n"
        + std::string("Last Name: Macdonald") + "\n"
        + std::string("Grades: 5 4 3 4 5") + "\n"
        + std::string("Student Id: 1") + "\n"
        + std::string("First Name: Declan") + "\n"
        + std::string("Last Name: Lewis") + "\n"
        + std::string("Grades: 4 5 5 2 3 3") + "\n"
        + std::string("Group Title: Title") + "\n"
        + std::string("Group Specialization: Specialization") + "\n"
        + std::string("Group Head: Id: 0, First Name: Rory, Last Name: Macdonald") + "\n"
        + std::string("Students: 0 1") + "\n", streamWriter.str());

    delete students[0];
    delete students[1];
    delete groups[0];
}

TEST(DeaneryTests, CarryOutHeadElectionTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    std::vector<Group *> groups
    {
        new Group("Title", "Specialization", students, nullptr)
    };

    Deanery deanery(nullptr, &students, &groups);
    deanery.CarryOutHeadElection();

    EXPECT_EQ(students[0]->GetId(), groups[0]->GetHead()->GetId());

    delete students[0];
    delete students[1];
    delete groups[0];
}

TEST(DeaneryTests, MoveStudentTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    std::vector<Group *> groups
    {
        new Group("Title 0", "Specialization 0", std::vector<Student *> { students[0], students[1] }, students[0]),
        new Group("Title 1", "Specialization 1", std::vector<Student *> { }, nullptr)
    };

    Deanery deanery(nullptr, &students, &groups);
    deanery.MoveStudent(students[0], *groups[0], *groups[1]);

    ASSERT_EQ(1, groups[1]->GetStudents()->size());
    EXPECT_EQ(0, (*groups[1]->GetStudents())[0]->GetId());
    ASSERT_EQ(1, groups[0]->GetStudents()->size());
    EXPECT_EQ(1, groups[0]->GetHead()->GetId());
    EXPECT_EQ(1, (*groups[0]->GetStudents())[0]->GetId());

    delete students[0];
    delete students[1];
    delete groups[0];
    delete groups[1];
}

TEST(DeaneryTests, ExpellStudentsTest)
{
    std::vector<Student *> students
    {
        new Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        new Student(1, "Declan", "Lewis", std::vector<int8_t> { 2, 2, 2, 2, 2, 3 })
    };
    std::vector<Group *> groups
    {
        new Group("Title 0", "Specialization 0", std::vector<Student *> { students[0], students[1] }, students[0])
    };

    Deanery deanery(nullptr, &students, &groups);
    deanery.ExpellStudents(3.0);

    ASSERT_EQ(1, students.size());
    EXPECT_EQ(0, students[0]->GetId());
    ASSERT_EQ(1, groups[0]->GetStudents()->size());
    EXPECT_EQ(0, (*groups[0]->GetStudents())[0]->GetId());

    delete students[0];
    delete groups[0];
}
