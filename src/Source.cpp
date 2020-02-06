#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Deanery.h"
#include "Group.h"
#include "Student.h"

using namespace std;

int main()
{
	FILE *fp = freopen("out.txt", "r", stdin);
	FILE *fp1 = freopen("out1.txt", "w", stdout);

	string s;
	while (getline(cin, s))
	{
		cout << s << "\\n";
	}
	fclose(fp);
	fclose(fp1);
}

int main()
{
	FILE *fp = freopen("out.txt", "w", stdout);

	Deanery* deanery = new Deanery();
	deanery->AddStudentsFromFile("inputS.txt");
	deanery->AddRandomMarks(15);
	deanery->StartHeadmenElections();
	std::string s = deanery->GetStatistics();

	cout << s;

	fclose(fp);
}