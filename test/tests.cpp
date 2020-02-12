#include "gtest/gtest.h"
#include "Deanery.h"
#include <string>

TEST(lab5, task1){
Group* group = new Group("19БИ-2");
EXPECT_EQ("19БИ-2", group->GetTitle());
delete group;
}

TEST(lab5, task2){
Student* student = new Student("Ювелева Екатерина Леонидовна");
student->addMark(4);
student->addMark(6);
EXPECT_EQ(5,student->GetAverageMark());
delete student;
}

TEST(lab5, task3){
Student* student = new Student("Ювелева Екатерина Леонидовна");
EXPECT_EQ("Ювелева Екатерина Леонидовна", student->GetFio());
delete student;
}

TEST(lab5, task4){
Group* group = new Group("19БИ-2");
Student* s1 = new Student("Ювелева Екатерина Леонидовна");
Student* s2 = new Student("Астанков Петр Аникитевич");
group->addStudent(s1);
group->addStudent(s2);
s1->addMark(9);
s2->addMark(7);
EXPECT_EQ(8,group->GetAverageGroupMark());
delete group;
}