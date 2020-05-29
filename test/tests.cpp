#include "gtest/gtest.h"
#include "Dean.h"
#include "Group.h"
#include "Student.h"
#include <vector>
#include <string>

TEST(lab5, test1){
    Dean hse;
    hse.createGroup("котики", "сон");
    int groupsNum = hse.getGroups().size();
    int result = 1;
    EXPECT_EQ(groupsNum, result);
}

TEST(lab5, test2){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулка");
    hse.createGroup("хомячки", "еда");
    hse.createGroup("птички", "вода");
    hse.createGroup("рыбки", "воздух");
    hse.createGroup("18ПИ-2", "компьютеры");
    hse.createGroup("чупокабры", "не придумал");
    int groupsNum = hse.getGroups().size();
    int result = 7;
    EXPECT_EQ(groupsNum, result);
}

TEST(lab5, test3){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулка");
    hse.createGroup("хомячки", "еда");
    std::string groupName = hse.addStudent("Иван");
    std::string result = "котики";
    EXPECT_EQ(groupName, result);
}


TEST(lab5, test4){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулка");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    std::string groupName = hse.addStudent("Вася");
    std::string result = "собачки";
    EXPECT_EQ(groupName, result);
}

TEST(lab5, test5){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулка");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    auto groups = hse.getGroups();
    int groupSize = groups[0].getSize();
    int result = 5;
    EXPECT_EQ(groupSize, result);
}

TEST(lab5, test6){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулка");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    int studentTested = hse.testStudents();
    int result = 4*3 + 1;
    EXPECT_EQ(studentTested, result);
}

TEST(lab5, test7){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулки");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    auto groups = hse.getGroups();
    std::string spec = groups[1].getSpecialty();
    std::string result = "прогулки";
    EXPECT_EQ(spec, result);
}

TEST(lab5, test8){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулки");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    for(int i = 0; i < 3; i++)
        hse.testStudents();
    int numOfMarks = hse.getGroups()[1].getStudents()[0].getMarks().size();
    int result = 3;
    EXPECT_EQ(numOfMarks, result);
}


TEST(lab5, test9){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулки");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    for(int i = 0; i < 3; i++)
        hse.testStudents();
    hse.clearing(11);
    int numOfStudents = hse.getGroups()[1].getSize();
    int result = 0;
    EXPECT_EQ(numOfStudents, result);
}
TEST(lab5, test10){
    Dean hse;
    hse.createGroup("котики", "сон");
    hse.createGroup("собачки", "прогулки");
    hse.createGroup("хомячки", "еда");
    for(int i = 0; i < 4*3 + 1; i++){
        char q = '0' + i;
        hse.addStudent("Иван" + q);
    }
    for(int i = 0; i < 3; i++)
        hse.testStudents();
    hse.clearing(0);
    int numOfStudents = hse.getGroups()[1].getSize();
    int result = 4;
    EXPECT_EQ(numOfStudents, result);
}