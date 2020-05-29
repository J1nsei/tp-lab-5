#include "gtest/gtest.h"
#include "mainInc.h"

//basic functions test
//group creation and group search
TEST(test1,task1)
{
    Deanery dean;
    dean.createGroup("testGroup", "testSpec");
    
    EXPECT_EQ("testGroup", dean.findGroup("testGroup")->getTitle());
}

//students creation and student search
TEST(test1, task2)
{
    Deanery dean;
    dean.createGroup("testGroup", "testSpec");
    dean.findGroup("testGroup")->addStudent(new Student("testStudent", 0));

    EXPECT_EQ("testStudent", dean.findGroup("testGroup")->findStudent(0)->getName());
}


//deleting student
TEST(test1, task3)
{
    Deanery dean;
    dean.createGroup("testGroup", "testSpec");
    Group* temp = dean.findGroup("testGroup");
    temp->addStudent(new Student("testStudent", 0));
    temp->deleteStudent(temp->findStudent(0));

    EXPECT_EQ(nullptr, dean.findGroup("testGroup")->findStudent(0));
}

//deleting non-existent student
TEST(test1, task3_1)
{
    Deanery dean;
    dean.createGroup("testGroup", "testSpec");
    Group* temp = dean.findGroup("testGroup");
    temp->addStudent(new Student("testStudent", 0));
    temp->deleteStudent(temp->findStudent(0));  
    temp->deleteStudent(temp->findStudent(0));

    EXPECT_EQ(nullptr, dean.findGroup("testGroup")->findStudent(0));
}

//changing students group
TEST(test1, task4)
{
    Deanery dean;
    dean.createGroup("testGroup", "testSpec");
    dean.createGroup("testGroup2", "testSpec2");
    Group* temp = dean.findGroup("testGroup");
    Group* temp2 = dean.findGroup("testGroup2");
    temp->addStudent(new Student("testStudent", 0));
    dean.changeStGroup(temp->findStudent(0), temp2);

    EXPECT_EQ("testStudent", dean.findGroup("testGroup2")->findStudent(0)->getName());
}

