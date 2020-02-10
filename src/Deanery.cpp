#include "Deanery.h"

using namespace std;

Deanery::Deanery()
{
}


Deanery::~Deanery()
{
}
void Deanery::updateStudents()
{
	string line;

	ifstream in("Students.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			string fio = "";
			string groupName = "";
			int in = line.find(';');
			for (int i = 0; i < line.length(); i++)
			{
				if (i < in)
				{
					fio += line[i];
				}
				else if (i == in)
				{
					i++;
				}
				else if (i > in)
				{
					groupName += line[i];
				}
			}
			bool needCreateGroup = true;
			for (Group* group : groups)
			{
				if (group->getTitle() == groupName)
				{
					needCreateGroup = false;
					Student* student = new Student(fio, group, nextId);
					group->addStudent(student);
				}
			}
			if (needCreateGroup == true)
			{
				Group* group = new Group(groupName);
				Student* student = new Student(fio, group, nextId);
				group->addStudent(student);
				groups.push_back(group);
			}
			nextId++;
		}	
	}
	in.close();
}
void Deanery::printAllStudents()
{
	for (Group* group : groups)
	{
		for (Student* student : group->getStudens())
		{
			cout << student->getFio() << " " << group->getTitle() << " ";
			for (int i : student->getMarks())
			{
				cout << i << " ";
			}
			cout << endl;
		}
	}
}
void Deanery::getRandomMark(Student* student)
{
	srand(time(0));
	student->addMark(rand() % 10 + 1);
}
void Deanery::killBadStudents()
{
	for (Group* group : groups)
	{
		for (Student* student : group->getStudens())
		{
			if (student->getMean() < 2.5)
			{
				group->killStudent(student);
			}
		}
	}
}
void Deanery::saveDates()
{
	ofstream out;          // поток для записи
	out.open("Students.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for (Group* group : groups)
		{
			for (Student* student : group->getStudens())
			{
				out << student->getFio() << "; " << group->getTitle() << endl;
			}
		}
	}
	out.close();
}
void Deanery::updateAllHead()
{
	for (Group* group : groups)
	{
		group->chouseNewHead();
	}
}