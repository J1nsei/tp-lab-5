#include "dean.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

void Deanery::crGroups(string path)
{
	ifstream fin;
	fin.open(path);
	vector<string> grps;
	string str;
	while (!fin.eof())
	{
		str = "";
		getline(fin, str);
		grps.push_back(str);
		
	}
	string ttle, spc;
	for (auto name : grps)
	{
		int i = 0;
		while (name[i] != ':')
		{
			ttle += name[i];
			i++;
		}
		for (int j=i + 1; j < name.size(); j++)
		{
			spc += name[j];
		}
		Group* gr_name = new Group(ttle, spc);
		groups.push_back(gr_name);
		ttle = "";
		spc = "";
	}
	fin.close();
}
void Deanery::crStudents(string path)
{
	ifstream fin1;
	fin1.open(path);
	string str;
	int idNumber = ++lastId;
	vector<string> studs;
	while (!fin1.eof())
	{
		str = "";
		getline(fin1, str);
		studs.push_back(str);
	}
	for (auto stud : studs)
	{
		Student* stud_name = new Student(idNumber, stud);
		if (idNumber % 2 == 0)
			groups[0]->addStudent(stud_name);
		else if (idNumber % 3 == 0)
			groups[1]->addStudent(stud_name);
		else
			groups[2]->addStudent(stud_name);
		idNumber++;
	}
	lastId = idNumber;
	fin1.close();
}

void Deanery::addRandMarks()
{
	srand(time(NULL));
	for (auto group : groups)
	{
		for (auto student : group->students)
		{
			int amount = rand() % 10;
			for (int i = 0; i <= amount; i++)
			{
				student->marks.push_back(rand() % 10);
			}
		}
	}
}

void Deanery::printData()
{
	for (auto group : groups)
	{
		cout << group->title <<" "<< group->spec << endl;
		for (auto student : group->students)
		{
			cout << student->id << " " << student->fio << " Средний балл: " << student->middleMark() << " Все оценки: ";
			for (int i = 0; i < student->marks.size(); i++)
			{
				cout << student->marks[i]<<"-";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void Deanery::studTransfer(Group* group, Student* stud)
{
	stud->addGroup(group);
}

void Deanery::ripLazyStud()
{
	double minMidMark = 100;
	int idTmp;
	Group* grp=nullptr;
	for (auto group : groups)
	{
		for (auto student : group->students)
		{
			if (student->middleMark() < minMidMark)
			{
				minMidMark = student->middleMark();
				idTmp = student->id;
				grp = group;
			}
		}
	}
	grp->byeStudent(grp->searchStudentID(idTmp));
	grp->searchStudentID(idTmp)->group = nullptr;
}

void Deanery::saveNewData()
{
	ofstream fout;
	fout.open("Output.txt");
	for (auto group : groups)
	{
		fout << group->title << " " << group->spec << endl;
		fout << "Средняя оценка группы " << group->middleGroupMark(group) << endl;
		fout << "Староста: " << group->head->fio << endl;
		for (auto student : group->students)
		{
			fout << student->id << " " << student->fio << " Средний балл: " << student->middleMark() << " Все оценки: ";
			for (int i = 0; i < student->marks.size(); i++)
			{
				fout << student->marks[i] << "-";
			}
			fout << endl;
		}
		fout << endl;
	}
	fout.close();
}

void Deanery::choiceGrHead()
{
	srand(time(NULL));
	for (auto group : groups)
	{
		int choice = rand() % group->students.size();
		group->headChoice(group->students[choice]);
	}
}

void Deanery::getStats()
{
	this->printData();
	for (auto group : groups)
	{
		cout << "Средняя оценка группы " << group->title << " " << group->middleGroupMark(group) << endl;
		cout << "Староста: " << group->head->fio << endl;
	}
}