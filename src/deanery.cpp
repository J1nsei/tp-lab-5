#include "Header.h"
#include "deanery.h"

Deanery::Deanery()
{
}

Deanery::~Deanery()
{
}


void Deanery::createGroups()
{
	ifstream gFile;
	gFile.open("groups.txt");
	if (gFile.is_open())
	{
		while (!gFile.eof())
		{
			string groupTitle;
			gFile >> groupTitle;
			Group *g = new Group(groupTitle);
			gFile >> groupTitle;
			g->setSpec(groupTitle);
			groups.push_back(g);
			string Check = "";
			while (Check != "!")
			{
				string fio, buf;
				int id;
				gFile >> fio;
				gFile >> buf;
				fio = fio + " " + buf;
				gFile >> id;
				Student* s = createStudent(fio, id, g);
				g->addStudent(s);
				gFile >> Check;
			}
		}
	}
}


void Deanery::setRandMarks()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		groups.at(i)->setRandMarks();
	}
}

void Deanery::printStatistic()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		cout << groups.at(i)->getTitle() << "  meanMark:  " << groups.at(i)->getMeanMark() << endl;
	}
}

void Deanery::printStatisticDetailed()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		groups.at(i)->printStatistic();

	}
}

void Deanery::transferStudent(Group* g_from, Group* g_to, Student* s)
{
	g_from->studentExpell(s);
	g_to->addStudent(s);
	s->addToGroup(g_to);
}

void Deanery::chooseHeadsRand()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		groups.at(i)->setRandHead();
	}
}

void Deanery::printHeads()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		groups.at(i)->getHead()->printStudentInf();
	}
}

void Deanery::noLowMarks()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{	
		Student* s = groups.at(i)->findLooser();
		while ( s != nullptr)
		{
			groups.at(i)->studentExpell(s);
			s = groups.at(i)->findLooser();
		}
	}
}

void Deanery::saveInform()
{
	ofstream gFile;
	gFile.open("groups.txt");
	
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		gFile << groups.at(i)->getTitle() <<" " << groups.at(i)->getSpec() << endl;
		groups.at(i)->saveStudents(gFile);
	}
	gFile.close();
}

Group* Deanery::findGroup(string title)
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		if (groups.at(i)->getTitle() == title)
		{
			return groups.at(i);
		}
	}
	return nullptr;
}

Student* Deanery::findStudent(int id)
{
	
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		Student* st = nullptr;
		st = groups.at(i)->findStudent(id);
		if (st != nullptr) {
			return st;
		}
	}
	return nullptr;
}



returns Deanery::addGroup(Group* group)
{
	groups.push_back(group);
	return OK;
}

void Deanery::printGroups()
{
	int n = groups.size();
	for (int i = 0; i < n; i++)
	{
		cout << groups.at(i)->getTitle() << "  " << groups.at(i)->getSpec() << endl;
		groups.at(i)->printStudents();
	}
}

Student* Deanery::createStudent(string fio, int id, Group* group)
{

	Student* s = new Student(id, fio);
	//s->addToGroup(group);
	
	return s;
}