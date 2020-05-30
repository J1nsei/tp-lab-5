#include "gtest/gtest.h"
#include "dean.h"
#include "student.h"
#include <string>

TEST(task1, dean_1){
    Student* student = new Student(1, "Бычков Илья Сергеевич");
    EXPECT_EQ("Бычков Илья Сергеевич", student->getFio());
    EXPECT_EQ(1, student->getId());
    delete student;
}
TEST(task1, dean_2){
    Student* student = new Student(1, "Бычков Илья Сергеевич");
    student->addMark(5);
    EXPECT_EQ(5.0, student->getAverageMark());
    delete student;
}