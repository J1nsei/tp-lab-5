#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using  namespace std;

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

string filePath(string filename) //filePath("/filname.txt") -> "/home/filname.txt"
{
	string pwd = exec("pwd");
	pwd.pop_back();
	string cl = "";
	cl = cl + pwd;
	cl = cl + "/";
	cl = cl + filename;
	return cl;
}


TEST(deanery, deanery_create) {
	Deanery deanery; 
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|PI2" <<endl;
	file << "Danilov Sergey|PMI" <<endl;
	file << "Valeryu Polyakov|PMI" <<endl;
	EXPECT_EQ(-1,deanery.extractDataFromFile(""));
	EXPECT_EQ(0, deanery.extractDataFromFile(testFilePath));
	EXPECT_EQ(1, deanery.searchStudent("Sergey").size());
	EXPECT_EQ(1, deanery.searchStudent("Valeryu Polyakov").size());
	EXPECT_EQ(0, deanery.searchStudent("Valeryu").size());
	Student* test_student = deanery.searchStudent("Valeryu Polyakov")[0];
	EXPECT_EQ("PMI", test_student->getGroup()->getTitle());
}

TEST(deanery, student) {
	Deanery deanery;
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|PI2" << endl;
	file << "Danilov Sergey|PMI" << endl;
	file << "Valeryu Polyakov|PMI"<<endl;
	EXPECT_EQ(0, deanery.extractDataFromFile(testFilePath));
	EXPECT_NE(0, deanery.searchStudent("Valeryu Polyakov").size());
	Student* test_student = deanery.searchStudent("Valeryu Polyakov")[0];
	EXPECT_EQ("Valeryu Polyakov", test_student->getFio());
	EXPECT_EQ("PMI", test_student->getGroup()->getTitle());
	EXPECT_EQ(3, test_student->getId());
}

TEST(deanery, group) {
	Deanery deanery;
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|PI2" << endl;
	file << "Danilov Sergey|PMI" <<endl;
	file << "Valeryu Polyakov|PMI" << endl;
	EXPECT_EQ(0, deanery.extractDataFromFile(testFilePath));
	Group* test_group = deanery.searchGroup("PMI");
	EXPECT_EQ("PMI", test_group->getTitle());
	EXPECT_EQ(0, test_group->getAvr());
}

TEST(deanery, marks) {
	Deanery deanery;
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|PI2" << endl;
	file << "Danilov Sergey|PMI" << endl;
	file << "Valeryu Polyakov|PMI" << endl;
	EXPECT_EQ(0, deanery.extractDataFromFile(testFilePath));
	Group* test_group = deanery.searchGroup("PMI");
	deanery.randMarks();
	deanery.randMarks();
	deanery.randMarks();
	EXPECT_NE(0, test_group->getAvr());
}

TEST(deanery, election) {
	Deanery deanery;
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|PI2" <<endl;
	file << "Danilov Sergey|PMI"<<endl;
	file << "Valeryu Polyakov|PMI"<<endl;
	EXPECT_EQ(0, deanery.extractDataFromFile(testFilePath));
	Group* test_group = deanery.searchGroup("PMI");
	deanery.electionHead();
	ASSERT_NE(test_group->getHead(), nullptr);
}


