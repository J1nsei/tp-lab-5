#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

TEST(student, test1) {
	Student* student = new Student("Goodwin Carol Georgiana", 1);
	student->addMark(2);
	student->addMark(4);
	student->addMark(5);
	student->addMark(1);
	student->addMark(2);
	int len = student->getMarks().size();
	EXPECT_EQ(5, len);
	}

TEST(student, test2) {
	Student* student = new Student("Goodwin Carol Georgiana", 1);
	student->addMark(5);
	student->addMark(3);
	student->addMark(4);
	double avrg = student->averageMark();
	EXPECT_EQ(4 avrg);
	}
	
TEST(group, test1) {
	Student* student = new Student("Goodwin Carol Georgiana", 1);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student);
	string group_name = student->getGroup()->getGroupName();
	EXPECT_EQ("18ECO-3", group_name);
	}

TEST(group, test2) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->removeStudent(student1);
	Group* group_name = student->getGroup();
	EXPECT_EQ(nullptr, group_name);
	}
	
TEST(group, test3) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Student* student3 = new Student("Bryant Patricia Doreen", 3);
	Student* student4 = new Student("Price Magdalene Kerrie", 4);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->addStudent(student3);
	economy->addStudent(student4);
	student1->addMark(4);
	student1->addMark(3);
	student2->addMark(5);
	student2->addMark(5);
	student3->addMark(5);
	student3->addMark(4);
	student4->addMark(1);
	student4->addMark(1);
	double avrg = economy->averageGroupMark();
	EXPECT_EQ(3.5, avrg);
	}
	
TEST(group, test4) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Student* student3 = new Student("Bryant Patricia Doreen", 3);
	Student* student4 = new Student("Price Magdalene Kerrie", 4);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->addStudent(student3);
	economy->addStudent(student4);
	head* head_name = economy->chooseHead();
	EXPECT_EQ(head_name->getName(), economy->getGroupHead()->getName());
	}
	
TEST(group, test5) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Student* student3 = new Student("Bryant Patricia Doreen", 3);
	Student* student4 = new Student("Price Magdalene Kerrie", 4);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->addStudent(student3);
	economy->addStudent(student4);
	Student* student_name = economy->findStudent("Bryant Patricia Doreen");
	EXPECT_EQ(student_name, student3);
	}
	
TEST(group, test6) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Student* student3 = new Student("Bryant Patricia Doreen", 3);
	Student* student4 = new Student("Price Magdalene Kerrie", 4);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->addStudent(student3);
	economy->addStudent(student4);
	Student* student_name = economy->findStudent(4);
	EXPECT_EQ(student_name, student4);
	}	
	
TEST(group, test7) {
	Student* student1 = new Student("Goodwin Carol Georgiana", 1);
	Student* student2 = new Student("Skinner Karen Martha", 2);
	Student* student3 = new Student("Bryant Patricia Doreen", 3);
	Student* student4 = new Student("Price Magdalene Kerrie", 4);
	Group* economy = new Group("18ECO-3", "Economy");
	economy->addStudent(student1);
	economy->addStudent(student2);
	economy->addStudent(student3);
	economy->addStudent(student4);
	Student* student_name = economy->findStudent("Flowers Shauna Constance");
	EXPECT_EQ(student_name, nullptr);
	}	
	
TEST(deanery, test1) {
	Group* math1 = new Group("18FM-1", "Mathematics");
	Group* math2 = new Group("18FM-2", "Mathematics");
	Group* math3 = new Group("18FM-3", "Mathematics");
	Deanery* imikn = new Deanery();
	imikn->addGroup(math1);
	imikn->addGroup(math2);
	imikn->addGroup(math3);
	Group* group_name = Deanery->findGroup("18FM-2");
	EXPECT_EQ(group_name, math2);
	}		
	
TEST(deanery, test2) {
	Deanery* imikn = new Deanery();
	Group* math = new Group("18FM-1", "Mathematics");
	Group* economy = new Group("18ECO-3", "Economy");
	Student* student1 = new Student("Watson Jane Sherilyn", 1);
	Student* student2 = new Student("Bond Alice Lorin", 2);
	imikn->addGroup(math);
	imikn->addGroup(economy);
	math->addStudent(student1);
	economy->addStudent(student2);
	Deanery->transferStudent("Watson Jane Sherilyn", "18ECO-3");
	string group_spec = economy->findStudent("Watson Jane Sherilyn")->getGroup()->getGroupSpec();
	EXPECT_EQ(group_spec, "Economy");
	EXPECT_EQ(economy->getGroupStudents().size(), 1);
	}		
		
TEST(deanery, test3) {
	Deanery* imikn = new Deanery();
	Group* math = new Group("18FM-1", "Mathematics");
	Student* student1 = new Student("Watson Jane Sherilyn", 1);
	Student* student2 = new Student("Bryan Irene Mary", 2);
	Student* student3 = new Student("Bond Alice Lorin", 3);
	Student* student4 = new Student("Ball Mary Jean", 4);
	imikn->addGroup(math);
	math->addStudent(student1);
	math->addStudent(student2);
	math->addStudent(student3);
	math->addStudent(student4);
	student1->addMark(3);
	student1->addMark(5);
	student2->addMark(4);
	student2->addMark(4);
	student3->addMark(2);
	student3->addMark(2);
	student4->addMark(4);
	student4->addMark(1);
	Deanery->removeStudents(3);
	int len = math->getGroupStudents().size();
	EXPECT_EQ(len, 2);
	}		
	
	
	
	
