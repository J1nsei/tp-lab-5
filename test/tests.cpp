#include "Dean.h"
#include "Student.h"
#include "Group.h"
#include "gtest/gtest.h"

#define students_path "../text/students.txt"
#define deanery_path  "../text/deanery.txt"
TEST(TestStudent, createFromFile) {
    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    map<string,vector<vector<string>>> dataMap;
    dean->showData(dataMap);
    EXPECT_GT(dataMap.size(), 0);
    EXPECT_GT(dataMap["ПИ"].size(), 0);
}