#include "gtest/gtest.h"
#include <Dean.h>
#include <Student.h>
#include <Group.h>

TEST(task1, task1_1) {
    Dean* dean = new Dean();
    EXPECT_EQ(93, dean->Get_students().size());
    delete dean;
}

TEST(task1, task1_2) {
    Dean* dean = new Dean();
    EXPECT_EQ(5, dean->Get_groups().size());
    delete dean;
}
TEST(task1, task1_3) {
    Dean *dean = new Dean();
    dean->Add_student("Железин Михаил", "18PI1");
    Group *group = dean->Search_of_group("18PI1");
    Student *student = group->Search_of_student("Железин Михаил");
    for (int i = 0; i < 10; i++) {
        student->Add_mark(i);
    }
    EXPECT_EQ(4.5, student->Calc_aver_mark());
}
TEST(task1, task1_4) {
    Dean *dean = new Dean();
    dean->Add_group("linguistics", "humanities");
    dean->Add_student("Козлова Оксана", "linguistics");
    Group *group = dean->Search_of_group("linguistics");
    Student *student = group->Search_of_student("Козлова Оксана");
    EXPECT_EQ("linguistics", group->Get_title());
    EXPECT_EQ(1, group->Get_size());
}


TEST(task1, task1_5) {
    Dean* dean = new Dean();
    Student* student1 = dean->Get_students()[0];
    Group*from = dean->Search_of_group(student1->Get_Group());
    Group* to = dean->Search_of_group("18PI2");
    string Name_of_student = student1->Get_fio();
    from->Exclusion_student(Name_of_student);
    to->Add_student(student1);
    EXPECT_EQ(nullptr, from->Search_of_student(Name_of_student));
    EXPECT_NE(nullptr, to->Search_of_student(Name_of_student));
    delete dean;

}
