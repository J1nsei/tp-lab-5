#include "gtest/gtest.h"
#include "Deanery.h"

TEST(task1, test1) {
    Deanery* dean = new Deanery();
    EXPECT_EQ(25, dean->groups[0]->getNumberStudents());
    EXPECT_EQ(24, dean->groups[7]->getNumberStudents());
    delete dean;
}

TEST(task1, test2) {
    Deanery* dean = new Deanery();
    dean->moveStudent("Мячина Ева Тарасовна", "19ПМИ-2", "19ПМИ-1");
    dean->moveStudent("Ланцов Александр Данилевич", "19ПМИ-2", "19ПМИ-1");
    EXPECT_EQ(27, dean->groups[6]->getNumberStudents());
    EXPECT_EQ(22, dean->groups[7]->getNumberStudents());
    delete dean;
}


TEST(task1, test3) {
    Deanery* dean = new Deanery();
int size = dean->groups[7]->getNumberStudents();
    dean->cickStudent("Ланцов Александр Данилевич");
    EXPECT_EQ(size-1, dean->groups[7]->getNumberStudents());
    delete dean;
}

TEST(task1, test4) {
    Deanery* dean = new Deanery();
    int size = dean->groups[7]->getNumberStudents();
    dean->addStudent("Соловьев Илья Максимович", "19ПМИ-2");
    Student *student = dean->findStudent("Соловьев Илья Максимович");
    EXPECT_EQ(size+1, dean->groups[7]->getNumberStudents());
    delete dean;
}


