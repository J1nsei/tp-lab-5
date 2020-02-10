//#include "pch.h"
#include "gtest/gtest.h"
#include <string>
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

//TEST(DeaneryTest, checkingStudentsReading) {
//	Deanery* deanery = new Deanery();
//	deanery->AddStudentsFromFile("inputS.txt");
//	std::string s = deanery->GetStatistics();
//	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\n", s);
//}


//TEST(DeaneryTest, checkingGroupReading) {
//	Deanery* deanery = new Deanery();
//	deanery->AddGroupsFromFile("inputG.txt");
//	std::string s = deanery->GetStatistics();
//	EXPECT_EQ("101:\n\n103:\n\n104:\n\n", s);
//}

TEST(DeaneryTest, checkingAddingMarks) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 2 2 2 4 3 \nBalaban Vsevolod: 2 5 5 4 4 \nBozhkov Emmanuil: 1 4 5 1 4 \nKusakov Zotik: 1 5 5 2 4 \n\nC:\nLubyanovskiy Timur: 2 2 2 4 3 \nMartynov Anaklet: 2 5 5 4 4 \n\nA:\nAlmazov Evfrasiy: 2 2 2 4 3 \nMitropolskiy Gleb: 2 5 5 4 4 \nBerdyaev Yulian: 1 4 5 1 4 \n\nG:\nHanykov Ustin: 2 2 2 4 3 \n\n", s);
}

TEST(DeaneryTest, checkingAddingStudentToGroup) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	Student* student = new Student("Maxim Zarkov", deanery);
	Group* group1 = deanery->AddGroup("G_unit");
	Group* group2 = deanery->AddGroup("bad_company");
	group1->AddStudent(student);
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\nG_unit:\nMaxim Zarkov: \n\nbad_company:\n\n", s);
}

TEST(DeaneryTest, checkingStudentsTransfer) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	Student* student = new Student("Maxim Zarkov", deanery);
	Group* group1 = deanery->AddGroup("G_unit");
	Group* group2 = deanery->AddGroup("bad_company");
	group1->AddStudent(student);
	deanery->StudentsTransfer(student, group1, group2);
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: \nBalaban Vsevolod: \nBozhkov Emmanuil: \nKusakov Zotik: \n\nC:\nLubyanovskiy Timur: \nMartynov Anaklet: \n\nA:\nAlmazov Evfrasiy: \nMitropolskiy Gleb: \nBerdyaev Yulian: \n\nG:\nHanykov Ustin: \n\nG_unit:\n\nbad_company:\nMaxim Zarkov: \n\n", s);
}

TEST(DeaneryTest, checkingStudentsDeleting) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks(15);
	deanery->KickStudents();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \nBozhkov Emmanuil: 1 4 5 1 3 5 4 4 3 1 2 1 5 2 5 \n\nC:\nLubyanovskiy Timur: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \n\nA:\nAlmazov Evfrasiy: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \nBerdyaev Yulian: 1 4 5 1 3 5 4 4 3 1 2 1 5 2 5 \n\nG:\nHanykov Ustin: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \n\n", s);
}

TEST(DeaneryTest, checkingHeadmenElections) {
	Deanery* deanery = new Deanery();
	//deanery->AddStudentsFromFile("inputS.txt");

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Lubyanovskiy Timur", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Bozhkov Emmanuil", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Almazov Evfrasiy", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Mitropolskiy Gleb", deanery);
	target->AddToAgroup(groupA);
	target = new Student("Hanykov Ustin", deanery);
	target->AddToAgroup(groupG);
	target = new Student("Martynov Anaklet", deanery);
	target->AddToAgroup(groupC);
	target = new Student("Kusakov Zotik", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Berdyaev Yulian", deanery);
	target->AddToAgroup(groupA);

	deanery->AddRandomMarks(15);
	deanery->StartHeadmenElections();
	std::string s = deanery->GetStatistics();
	EXPECT_EQ("B:\nLavrentev Miloslav: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \nBalaban Vsevolod: 1 5 5 2 4 3 3 1 3 4 1 1 2 3 3 \nBozhkov Emmanuil: 1 4 5 1 3 5 4 4 3 1 2 1 5 2 5 \nKusakov Zotik: 1 4 3 2 1 2 1 3 2 5 1 2 2 5 3 \n\nC:\nLubyanovskiy Timur: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \nMartynov Anaklet: 1 5 5 2 4 3 3 1 3 4 1 1 2 3 3 \n\nA:\nAlmazov Evfrasiy: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \nMitropolskiy Gleb: 1 5 5 2 4 3 3 1 3 4 1 1 2 3 3 \nBerdyaev Yulian: 1 4 5 1 3 5 4 4 3 1 2 1 5 2 5 \n\nG:\nHanykov Ustin: 2 2 2 4 3 2 5 5 4 4 1 4 5 1 4 \n\n", s);
}