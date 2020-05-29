#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

using namespace std;

//int main()
//{
//	FILE *fp = freopen("out.txt", "r", stdin);
//	FILE *fp1 = freopen("out1.txt", "w", stdout);
//
//	string s;
//	while (getline(cin, s))
//	{
//		cout << s << "\\n";
//	}
//	fclose(fp);
//	fclose(fp1);
//}

int main()
{
	FILE *fp = freopen("outC.txt", "w", stdout);
	//std::ofstream output("outF.txt");

	Deanery* deanery = new Deanery();

	Group* groupB = deanery->AddGroup("B");
	Group* groupC = deanery->AddGroup("C");
	Group* groupA = deanery->AddGroup("A");
	Group* groupG = deanery->AddGroup("G");

	Student* target = new Student("Lavrentev Miloslav", deanery);
	target->AddToAgroup(groupB);
	target = new Student("Balaban Vsevolod ", deanery);
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

	//deanery->AddStudentsFromFile("inputS.txt");
	deanery->AddRandomMarks(15);
	deanery->StartHeadmenElections();
	std::string s = deanery->GetStatistics();

	cout << s;

	//fclose(fp);
}