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
    ASSERT_GT(dataMap.size(), 0);
    ASSERT_GT(dataMap["ПИ"].size(), 0);
}

TEST(TestStudent, addGrades) {
    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    dean->addGrades(10);
    map<string,vector<vector<string>>> dataMap;
    dean->showData(dataMap);

    bool marksAdded = false;
    for (auto group:dataMap){
        for (auto student :group.second){
            if (stoi(student[2]) > 0){
                marksAdded = true;
            }
        }
    }
    EXPECT_EQ(marksAdded, true);
}