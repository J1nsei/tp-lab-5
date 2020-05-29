#include "Deanery.h"
#include "Student.h"

Deanery::Deanery(string file_students, string file_groups)
{
	FileStudents = file_students;
	FileGroups = file_groups;
}

void Deanery::makeStud()
{
	ifstream file(FileStudents);
	string fioStud;
	int idStud = 1;

	while (getline(file, fioStud))
	{
		allTheStudents.push_back(new Student(idStud, fioStud));
		idStud++;
	}
	file.close();
}

void Deanery::makeGroups()
{
	ifstream file(FileGroups);
	string TitleGroup;

	while (getline(file, TitleGroup))
	{
		groups.push_back(new Group(TitleGroup));
	}

	file.close();

	for (int i = 0; i < groups.size(); i++)
	{
		for (int j = i * (allTheStudents.size() / groups.size()); j < (i + 1) * (allTheStudents.size() / groups.size()); j++)
		{
			allTheStudents[j]->addToGroup(groups[i]->title);
			groups[i]->addStudent(allTheStudents[j]);
		}
	}
}

void Deanery::addMarks()
{
	int mark;

	for (int i = 0; i < allTheStudents.size(); i++)
	{
		mark = rand() % 5 + 1;
		allTheStudents[i]->setMarks(mark);
	}
}

void Deanery::stat()
{
	for (int i = 0; i < allTheStudents.size(); i++)
	{
		StatStud.push_back(pair<float, string>(allTheStudents[i]->getAvarageMarks(), allTheStudents[i]->FIO));
	}
	sort(StatStud.begin(), StatStud.end());

	for (int i = 0; i < groups.size(); i++)
	{
		StatGroup.push_back(pair<float, string>(groups[i]->averageMarkGroup(), groups[i]->title));
	}
	sort(StatGroup.begin(), StatGroup.end());

	cout << "~Students statistics~" << endl;
	for (int i = 0; i < StatStud.size(); i++)
	{
		cout << StatStud[i].second << ": " << StatStud[i].first << endl;
	}

	cout << endl;
	cout << "~Groups statistics~" << endl;
	for (int i = 0; i < StatGroup.size(); i++)
	{
		cout << StatGroup[i].second << ": " << StatGroup[i].first << endl;
	}
	cout << endl;
}

void Deanery::changeGroup(Student *stud, string title_target_group)
{
	for (int i = 0; i < groups.size(); i++)
	{
		if (groups[i]->title == title_target_group)
		{
			string lastgroup = stud->group;
			for (int j = 0; j < groups.size(); j++)
			{
				if (groups[j]->title == lastgroup)
				{
					groups[j]->deleteStudent(stud->ID);
				}
			}
			stud->addToGroup(groups[i]->title);
			groups[i]->addStudent(stud);
		}
	}
}

void Deanery::exclusion()
{
	for (int i = 0; i < allTheStudents.size(); i++)
	{
		if (allTheStudents[i]->getAvarageMarks() < 3)
		{
			string titlegroup = allTheStudents[i]->group;
			for (int j = 0; j < groups.size(); j++)
			{
				if (groups[j]->title == titlegroup)
				{
					groups[j]->deleteStudent(allTheStudents[i]->ID);
					allTheStudents.erase(allTheStudents.begin() + i);
					i--;
				}
			}
		}
	}
}

void Deanery::upd(string title_)
{
	ofstream file;
	file.open(title_);

	if (file.is_open())
	{
		file << "Number of students - " << allTheStudents.size() << endl << endl;
		for (int i = 0; i < groups.size(); i++) 
		{
			file << groups[i]->title << ": " << groups[i]->students.size() << " people" << endl;
			file << "Group average score - " << groups[i]->averageMarkGroup() << endl;
			file << "Group leader: " << groups[i]->head->FIO << endl;
			for (int j = 0; j < groups[i]->students.size(); j++)
			{
				file << groups[i]->students[j]->FIO << ": " << groups[i]->students[j]->getAvarageMarks() << "  ";
				for (int h = 0; h < groups[i]->students[j]->marks.size(); h++)
				{
					file << groups[i]->students[j]->marks[h] << " ";
				}
				file << endl;
			}
			file << endl;
		}
	}
	file.close();
}

void Deanery::leader()
{
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->headman();
	}
}

void Deanery::outputInform()
{
	cout << "Number of students -  " << allTheStudents.size() << endl;
	for (int i = 0; i < groups.size(); i++)
	{
		cout << "Group average score - " << groups[i]->averageMarkGroup() << endl;
		cout << "Group leader: " << groups[i]->head->FIO << endl;
		for (int j = 0; j < groups[i]->students.size(); j++)
		{
			cout << groups[i]->students[j]->FIO << ": " << groups[i]->students[j]->getAvarageMarks() << "   ";
			for (int h = 0; h < groups[i]->students[j]->marks.size(); h++)
			{
				cout << groups[i]->students[j]->marks[h] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << "~Students statistics~" << endl << endl;
	for (int i = 0; i < StatStud.size(); i++)
	{
		cout << StatStud[i].second << ": " << StatStud[i].first << endl;
	}

	cout << "~Groups statistics~" << endl << endl;
	for (int i = 0; i < StatGroup.size(); i++)
	{
		cout << StatGroup[i].second << ": " << StatGroup[i].first << endl;
	}
}

int Deanery::GetStudentsNumber()
{
	return allTheStudents.size();
}