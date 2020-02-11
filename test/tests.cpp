#include "gtest/gtest.h"
#include "Deanery.h"

TEST(task1, dean_1){
    Group* group = new Group("18PI-1")
    EXPECT_EQ("18PI-1", group->getTitle());
    delete group;
}

TEST(task1, dean_2){
    Student* student = new Student("Андрей Кленков Дмитриевич");
    student->addMark(7);
    student->addMark(9);
    EXPECT_EQ(8,student->getAverageMark());
    delete student;
}

TEST(task1, dean_3){
    Student* student = new Student("Андрей Кленков Дмитриевич");
    EXPECT_EQ("Андрей Кленков Дмитриевич", student->getFio());
    delete student;
}

TEST(task1, dean_4){
    Group* group = new Group("18PI-1");
    Student* student_1 = new Student("Иванов Иван Иванович");
    Student* student_2 = new Student("Смирнов Петр Александрович");
    group->addStudent(student_1);
    group->addStudent(student_2);
    student_1->addMark(6);
    student_2->addMark(8);
    EXPECT_EQ(7,group->getAverageGroupMark());
    delete group;
}

