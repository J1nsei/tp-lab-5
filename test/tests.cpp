#include "gtest/gtest.h"
#include "student.h"
#include "group.h"
#include "dean.h"

int Student::static_ID = 0;

TEST(lab5, test1)
{
    /*Dean* dean = new Dean("students.txt");
    EXPECT_EQ(dean->GetGroup("18ПИ-1")->FindStudent(0), dean->ChangeGroupOfStudent(dean->GetGroup("18ПИ-1"), dean->GetGroup("18ПИ-2"), 0));*/
    Student* student = new Student("Baranov Egor");
    student->AddMark(1);
    student->AddMark(2);
    student->AddMark(3);
    EXPECT_EQ(student->GetAverageMark(), 2);
}

/*TEST(lab5, test2)
{
    Dean* dean = new Dean("students.txt");
    EXPECT_EQ(dean->GetGroup("18ПИ-1")->FindStudent(1), dean->ChangeGroupOfStudent(dean->GetGroup("18ПИ-1"), dean->GetGroup("18ПИ-2"), 1));
}

TEST(lab5, test3)
{
    Dean* dean = new Dean("students.txt");
    EXPECT_EQ(dean->GetGroup("18ПИ-2")->FindStudent(2), dean->ChangeGroupOfStudent(dean->GetGroup("18ПИ-2"), dean->GetGroup("18ПИ-1"), 2));
}

TEST(lab5, test4)
{
    Dean* dean = new Dean("students.txt");
    EXPECT_EQ(dean->GetGroup("18ПИ-2")->FindStudent(3), dean->ChangeGroupOfStudent(dean->GetGroup("18ПИ-2"), dean->GetGroup("18ПИ-1"), 3));
}*/


