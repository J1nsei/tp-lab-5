#include "Dean.h"
#include "Student.h"
#include "Group.h"
#include "gtest/gtest.h"

#define students_path "../text/students.txt"
#define deanery_path  "../text/deanery.txt"
#define groups_path  "../text/groups.txt"

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

TEST(TestStudent, expelStudent) {
    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    dean->addGrades(10);
    map<string,vector<vector<string>>> dataMap;
    dean->showData(dataMap);
    unsigned int studentsWere = 0;
    for (auto group: dataMap){
        studentsWere+=group.second.size();
    }
    dean->expelStudents(7);
    dataMap.clear();
    unsigned int studentsAfterExpelling = 0;
    dean -> showData(dataMap);
    for (auto group: dataMap){
        studentsAfterExpelling+=group.second.size();
    }
    EXPECT_GT(studentsWere,studentsAfterExpelling);
}

TEST(TestStudent, migrateStudent) {
    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    dean->migrateStudent("ЮРИСТ",99,"ЭКОНОМ");
    map<string,vector<vector<string>>> dataMap;
    dean->showData(dataMap);
    bool Found = false;
    for (auto student:dataMap["ЭКОНОМ"]){
        if (stoi(student[1]) == 99){
            Found = true;
            break;
        }
    }
    EXPECT_EQ(Found,true);
}

TEST(TestStudent, saveFunc) {
    auto dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    dean->addGrades(8);
    map<string,vector<vector<string>>> dataMapBefore;
    dean->showData(dataMapBefore);
    dean->saveFiles(deanery_path,groups_path,students_path);
    delete dean;

    dean = new Dean{};
    dean->createGroups(deanery_path);
    dean->createStudents(students_path);
    map<string,vector<vector<string>>> dataMapAfter;
    dean->showData(dataMapAfter);

    bool AllEqual = true;
    try{
        for (auto & group: dataMapBefore){
            if (group.second != dataMapAfter[group.first]){
                AllEqual = false;
                break;
            }
        }
    }catch(...){
        FAIL() << "SAVEFILE FUNC IS NOT CORRECT";
    }
    EXPECT_EQ(AllEqual, true);
}