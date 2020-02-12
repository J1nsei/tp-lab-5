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
student->AddMark(4);
student->AddMark(6);
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
group->AddStudent(s1);
group->AddStudent(s2);
s1->AddMark(9);
s2->AddMark(7);
EXPECT_EQ(8,group->GetAverageGroupMark());
delete group;
}