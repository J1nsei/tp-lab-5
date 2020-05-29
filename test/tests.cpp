#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Dean.h"
#include <string>


TEST(GroupTests, checkCreatedGroup) {
	Dean* dean = new Dean("../file/students.csv");

	//success
	std::string groupName1 = "18PI-2";	
	Group* group1 = dean->findGroupByName(groupName1);	
	EXPECT_EQ(groupName1, group1->getName());

	//fail
	std::string groupName2 = "18PI-4";
	Group* group2 = dean->findGroupByName(groupName2);
	EXPECT_EQ(0, group2);
}

TEST(GroupTests, findStudentInGroup) {
	Dean* dean = new Dean("../file/students.csv");
	Group* group = dean->findGroupByName("18PI-2");

	//success
	Student* findStudent = group->findStudentById(35);
	std::string studentName1 = "Ковалевская Бронислава Тарасовна";
	EXPECT_EQ(studentName1, findStudent->getFIO());

	//fail
	Student* Igor = group->findStudentById(36);
	EXPECT_EQ(0, Igor);
}

TEST(StudentTests, studentInfo) {
	Dean* dean = new Dean("../file/students.csv");
	Student* student = dean->findStudentById(12);
	EXPECT_EQ("Вольваков Кузьма Трофимович", student->getFIO());
	EXPECT_EQ("18PI-1", student->getGroup()->getName());
}

TEST(StudentTests, addStudent) {
	Dean* dean = new Dean("../file/students.csv");
	Group* group = dean->findGroupByName("18PMI-1");
	dean->addNewStudent("Сидорова Мария Ивановна", group);
	Student* newStudent = group->findStudentByName("Сидорова Мария Ивановна");
	EXPECT_EQ(100, newStudent->getID());
}

TEST(StudentTests, expelStudent) {
	Dean* dean = new Dean("../file/students.csv");
	Student* Vasilisa = dean->findStudentById(80);
	dean->expelStudent(Vasilisa);
	EXPECT_EQ(0, dean->findStudentById(80));
}

TEST(StudentTests, transferStudent) {
	Dean* dean = new Dean("../file/students.csv");
	Student* student = dean->findStudentById(12);
	Group* group = dean->findGroupByName("18PMI-1");
	dean->studentTransfer(student, group);
	EXPECT_EQ("18PMI-1", student->getGroup()->getName());
}

TEST(StudentTests, groupHead) {
	Dean* dean = new Dean("../file/students.csv");
	Group* group = dean->findGroupByName("18PMI-1");
	Student* student = dean->findStudentById(11);
	group->setHead(student);
	EXPECT_EQ(student, group->getHead());
}

TEST(StudentTests, averageMark) {
	Dean* dean = new Dean("../file/students.csv");
	Student* student = dean->findStudentById(35);
	for (int i = 0; i < 5; i++) {
		student->addMark(i);
	}
	EXPECT_EQ(2, student->averageMark());
}