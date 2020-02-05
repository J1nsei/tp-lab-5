#include "gtest/gtest.h"
#include "../tp-lab-5/dean.h"
#include "../tp-lab-5/group.h"
#include "../tp-lab-5/student.h"

TEST(Deanery, dean_1) {
    Dean* dean = new Dean();
    EXPECT_EQ(4, dean->getGroups());
    delete dean;
}

TEST(Deanery, dean_2) {
    Dean* dean = new Dean();
    EXPECT_EQ(100, dean->getStudents());
    delete dean;
}

TEST(Deanery, dean_3) {
    Group* group = new Group("18-ПМИ");
    EXPECT_EQ("ПМИ", group->getSpec());
    delete group;
}

TEST(Deanery, dean_4) {
    Student* student = new Student("Полюхов Владислав Вадимович", "18-ПМИ");
    student->setMarks();
    EXPECT_EQ(10, student->getMarks().size());
    delete student;
}

TEST(Deanery, dean_5) {
	Student student_1;
	Student student_2("Полюхов Владислав Вадимович", "18-ПМИ");
	EXPECT_EQ(-1, student_1.getId());
	EXPECT_EQ(1, student_2.getId());
	EXPECT_EQ("18-ПМИ", student_2.getGroup());
	delete student_1;
	delete student_2;
}

TEST(Deanery, dean_6) {
	Group group("18-ПМИ");
    Student student("Полюхов Владислав Вадимович", "18-ПМИ");
	group.addStudent(student);

	EXPECT_EQ(1, group.findStudent("Полюхов Владислав Вадимович")->getId());
    delete student;
    delete group;
}