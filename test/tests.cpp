#include "gtest/gtest.h"
#include "../include/dean.h"
#include "../include/group.h"
#include "../include/student.h"

TEST(Deanery, dean_1) {
	Group* group = new Group("18-PMI");
	EXPECT_EQ("PMI", group->getSpec());
	delete group;
}

TEST(Deanery, dean_2) {
	Student* student = new Student("Ivanov Andrey Romanovich", "18-PMI");
	student->setMarks();
	EXPECT_EQ(10, student->getMarks().size());
	delete student;
}

TEST(Deanery, dean_3) {
	Student* student_1 = new Student();
	Student* student_2 = new Student("Ivanov Andrey Romanovich", "18-PMI");
	EXPECT_EQ(-1, student_1->getId());
	EXPECT_EQ(1, student_2->getId());
	EXPECT_EQ("18-PMI", student_2->getGroup());
	delete student_1;
	delete student_2;
}

TEST(Deanery, dean_4) {
	Group* group = new Group("18-PMI");
	Student* student = new Student("Ivanov Andrey Romanovich", "18-PMI");
	group->addStudent(*student);

	EXPECT_EQ(1, group->findStudent("Ivanov Andrey Romanovich")->getId());
	delete student;
	delete group;
}