
#include "Student.h"
#include "Group.h"
#include "Deanery.h"

#include <fstream>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

using namespace std;

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

int main() {
	/*
	Student student(12, "234");
	cout << student.getId() << " " << student.getFio() << endl;
	student.addMark(18);
	cout << student.getAvr() << endl;
	Group group("23");
	cout << group.addStudent(&student) << endl;
	cout << group.addStudent(&student) << endl;
	cout << group.searchStudent("2").size() << endl;
	Student student2(13, "234");
	cout << group.setHead(&student2) << endl;
	cout << group.eraseStudent(&student2) << endl;
	group.searchStudent(12)->addMark(5);
	group.searchStudent(12)->addMark(7);
	group.searchStudent(12)->addMark(9);
	cout << group.getAvr() << endl;
	group.setHead(&student);
	cout << group.getHead() << endl;
	group.eraseStudent(group.searchStudent(12));
	cout << group.getHead() << endl;
	*/
	cout << "START TESTING" << endl;
	string testFilePath = filePath("test.txt");
	ofstream file(testFilePath);
	file << "Sergey|uoi";
	Deanery deanery;
	deanery.extractDataFromFile(testFilePath);
	deanery.electionHead();
	cout << deanery.searchGroup("rt");
	cout << deanery.searchGroup("uoi");
	cout << deanery.eraseWithBadMarks(2.0);
	deanery.randMarks();
	cout << deanery.eraseWithBadMarks(9.0);
	deanery.getStatistics();
	deanery.electionHead();
	return 0;
}

