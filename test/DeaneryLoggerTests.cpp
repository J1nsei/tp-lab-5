#include <sstream>
#include "gtest/gtest.h"
#include "DeaneryLogger.h"
#include "Group.h"
#include "Student.h"

TEST(DeaneryLoggerTests, WriteStudentTest)
{
    Student student(16, "First Name", "Last Name", std::vector<int8_t> { 1, 2, 3, 4, 5 });

    std::ostringstream streamWriter;
    DeaneryLogger deaneryLogger(&streamWriter);

    deaneryLogger.WriteStudent(student);

    EXPECT_EQ(std::string("Student Id: 16") + "\n"
        + std::string("First Name: First Name") + "\n"
        + std::string("Last Name: Last Name") + "\n"
        + std::string("Grades: 1 2 3 4 5") + "\n", streamWriter.str());
}

TEST(DeaneryLoggerTests, WriteGroupTest)
{
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 })
    };
    Group group("Title", "Specialization", std::vector<Student *> { &(students[0]), &(students[1]) }, &(students[0]));

    std::ostringstream streamWriter;
    DeaneryLogger deaneryLogger(&streamWriter);

    deaneryLogger.WriteGroup(group);

    EXPECT_EQ(std::string("Group Title: Title") + "\n"
        + std::string("Group Specialization: Specialization") + "\n"
        + std::string("Group Head: Id: 0, First Name: Rory, Last Name: Macdonald") + "\n"
        + std::string("Students: 0 1") + "\n", streamWriter.str());
}
