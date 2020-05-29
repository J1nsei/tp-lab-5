#include <sstream>
#include "gtest/gtest.h"
#include "DatabaseProvider.h"
#include "Student.h"

TEST(DatabaseProviderTests, LoadStudentsTest)
{
    std::string studentsString = std::string("0\tRory\tMacdonald\t5\t4\t3\t4\t5") + "\n"
        + std::string("1\tDeclan\tLewis\t4\t5\t5\t2\t3\t3") + "\n"
        + std::string("2\tCaleb\tRobinson\t4\t2\t5\t3\t5") + "\n"
        + std::string("3\tRiley\tBarrett\t5\t3\t4\t5\t3\t5") + "\n";
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    std::istringstream studentsStreamReader(studentsString);
    DatabaseProvider databaseProvider("", "");

    databaseProvider.LoadStudents(studentsStreamReader);
    
    EXPECT_EQ(4, databaseProvider.GetStudents()->size());
    for (uint32_t i = 0; i < databaseProvider.GetStudents()->size(); i++)
    {
        EXPECT_EQ(students[i].GetId(), (*databaseProvider.GetStudents())[i]->GetId());
        EXPECT_EQ(students[i].GetFirstName(), (*databaseProvider.GetStudents())[i]->GetFirstName());
        EXPECT_EQ(students[i].GetLastName(), (*databaseProvider.GetStudents())[i]->GetLastName());
        EXPECT_EQ(students[i].GetGrades()->size(), (*databaseProvider.GetStudents())[i]->GetGrades()->size());
        for (uint32_t j = 0; j < (*databaseProvider.GetStudents())[i]->GetGrades()->size(); j++)
            EXPECT_EQ((*students[i].GetGrades())[j], (*(*databaseProvider.GetStudents())[i]->GetGrades())[j]);
    }
}

TEST(DatabaseProviderTests, LoadGroupsTest)
{
    std::string studentsString = std::string("0\tRory\tMacdonald\t5\t4\t3\t4\t5") + "\n"
        + std::string("1\tDeclan\tLewis\t4\t5\t5\t2\t3\t3") + "\n"
        + std::string("2\tCaleb\tRobinson\t4\t2\t5\t3\t5") + "\n"
        + std::string("3\tRiley\tBarrett\t5\t3\t4\t5\t3\t5") + "\n";
    std::string groupsString = std::string("Software Engineering 18\tA very long description of the specialization\t0\t1") + "\n"
        + std::string("Design 18\tAnother very long description\t3\t2") + "\n";

    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    std::vector<Group> groups
    {
        Group("Software Engineering 18", "A very long description of the specialization", std::vector<Student *> { &(students[0]), &(students[1]) }, &(students[0])),
        Group("Design 18", "Another very long description", std::vector<Student *> { &(students[3]), &(students[2]) }, &(students[3]))
    };
    std::istringstream studentsStreamReader(studentsString);
    std::istringstream groupsStreamReader(groupsString);
    DatabaseProvider databaseProvider("", "");

    databaseProvider.LoadStudents(studentsStreamReader);
    databaseProvider.LoadGroups(groupsStreamReader);

    EXPECT_EQ(2, databaseProvider.GetGroups()->size());
    for (uint32_t i = 0; i < databaseProvider.GetGroups()->size(); i++)
    {
        EXPECT_EQ(groups[i].GetTitle(), (*databaseProvider.GetGroups())[i]->GetTitle());
        EXPECT_EQ(groups[i].GetSpecialization(), (*databaseProvider.GetGroups())[i]->GetSpecialization());
        EXPECT_EQ(groups[i].GetHead()->GetId(), (*databaseProvider.GetGroups())[i]->GetHead()->GetId());
        EXPECT_EQ(groups[i].GetStudents()->size(), (*databaseProvider.GetGroups())[i]->GetStudents()->size());
        for (uint32_t j = 0; j < (*databaseProvider.GetGroups())[i]->GetStudents()->size(); j++)
            EXPECT_EQ((*groups[i].GetStudents())[j]->GetId(), (*(*databaseProvider.GetGroups())[i]->GetStudents())[j]->GetId());
    }
}

TEST(DatabaseProviderTests, SaveStudentsTest)
{
    std::string studentsString = std::string("0\tRory\tMacdonald\t5\t4\t3\t4\t5") + "\n"
        + std::string("1\tDeclan\tLewis\t4\t5\t5\t2\t3\t3") + "\n"
        + std::string("2\tCaleb\tRobinson\t4\t2\t5\t3\t5") + "\n"
        + std::string("3\tRiley\tBarrett\t5\t3\t4\t5\t3\t5") + "\n";
    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    std::ostringstream studentsStreamWriter;
    DatabaseProvider databaseProvider("", "");

    for (uint32_t i = 0; i < students.size(); i++)
        databaseProvider.GetStudents()->push_back(&(students[i]));

    databaseProvider.SaveStudents(studentsStreamWriter);

    EXPECT_EQ(studentsString, studentsStreamWriter.str());
}

TEST(DatabaseProviderTests, SaveGroupsTest)
{
    std::string groupsString = std::string("Software Engineering 18\tA very long description of the specialization\t0\t1") + "\n"
        + std::string("Design 18\tAnother very long description\t3\t2") + "\n";

    std::vector<Student> students
    {
        Student(0, "Rory", "Macdonald", std::vector<int8_t> { 5, 4, 3, 4, 5 }),
        Student(1, "Declan", "Lewis", std::vector<int8_t> { 4, 5, 5, 2, 3, 3 }),
        Student(2, "Caleb", "Robinson", std::vector<int8_t> { 4, 2, 5, 3, 5 }),
        Student(3, "Riley", "Barrett", std::vector<int8_t> { 5, 3, 4, 5, 3, 5 })
    };
    std::vector<Group> groups
    {
        Group("Software Engineering 18", "A very long description of the specialization", std::vector<Student *> { &(students[0]), &(students[1]) }, &(students[0])),
        Group("Design 18", "Another very long description", std::vector<Student *> { &(students[3]), &(students[2]) }, &(students[3]))
    };
    std::ostringstream groupsStreamWriter;
    DatabaseProvider databaseProvider("", "");

    for (uint32_t i = 0; i < students.size(); i++)
        databaseProvider.GetStudents()->push_back(&(students[i]));
    for (uint32_t i = 0; i < groups.size(); i++)
        databaseProvider.GetGroups()->push_back(&(groups[i]));

    databaseProvider.SaveGroups(groupsStreamWriter);

    EXPECT_EQ(groupsString, groupsStreamWriter.str());
}
