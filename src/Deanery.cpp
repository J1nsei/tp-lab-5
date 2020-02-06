#include "Deanery.h" //fix
#include <fstream>
#include <iostream>
#include <algorithm>

Deanery::Deanery(string file_students, string file_groups)
{
	FileStudents = file_students;
	FileGroups = file_groups;
}

void Deanery::MakeStudents()
{
	ifstream file(FileStudents);
	string FioStudent;
	int idd = 1;
	while (getline(file, FioStudent))
	{
		allstudents.push_back(new Student(idd, FioStudent));
		idd++;
	}
	file.close();
}

void Deanery::MakeGroups()
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
		for (int j = i * (allstudents.size()/groups.size()) ; j < (i + 1) * (allstudents.size() / groups.size()); j++)
		{
			allstudents[j]->AddGroup(groups[i]->title);
			groups[i]->AddStudent(allstudents[j]);
		}
	}
}

void Deanery::AddMarks()
{
	int mark;
	for (int i = 0; i < allstudents.size(); i++) 
	{
			mark = rand() % 5 + 1;
			allstudents[i]->AddMark(mark);
	}
}

void Deanery::HeadInit()
{
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->HeadElection();
	}
}

void Deanery::StudentException() 
{
	for (int i = 0; i < allstudents.size(); i++) 
	{
		if (allstudents[i]->AverageBall() < 3) 
		{
			string titlegroup = allstudents[i]->group;
			for (int j = 0; j < groups.size(); j++)
			{
				if (groups[j]->title == titlegroup)
				{
					groups[j]->DeleteStudent(allstudents[i]->id);
					allstudents.erase(allstudents.begin() + i);
					i--;
				}
			}
		}
	}
}

void Deanery::ChangeGroup(Student *stud, string title_target_group)
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
					groups[j]->DeleteStudent(stud->id);
				}
			}
			stud->AddGroup(groups[i]->title);
			groups[i]->AddStudent(stud);
		}
	}
}

void Deanery::Statistics()
{
	for (int i = 0; i < allstudents.size(); i++) 
	{
		StatStud.push_back(pair<float, string>(allstudents[i]->AverageBall(), allstudents[i]->fio));
	}sort(StatStud.begin(), StatStud.end());

	for (int i = 0; i < groups.size(); i++) 
	{
		StatGroup.push_back(pair<float, string>(groups[i]->AverageGroup(), groups[i]->title));
	}sort(StatGroup.begin(), StatGroup.end());

	cout << "Students statistics:" << endl;
	for (int i = 0; i < StatStud.size(); i++)
	{
		cout<< StatStud[i].second << "-" << StatStud[i].first << endl;
	}

	cout << "Groups statistics:" << endl;
	for (int i = 0; i < StatGroup.size(); i++)
	{
		cout << StatGroup[i].second << "-" << StatGroup[i].first << endl;
	}
}

void Deanery::Update(string title_)
{
	ofstream file;
	file.open(title_);

	if (file.is_open())
	{
		file << "The number of students is  " << allstudents.size() << endl;
		for (int i = 0; i < groups.size(); i++) {
			file << "In " << groups[i]->title << " " << groups[i]->students.size() << " people. " << " The averade groups mark - " << groups[i]->AverageGroup() << endl;
			file << "Head: " << groups[i]->head->fio << endl;
			for (int j = 0; j < groups[i]->students.size(); j++) 
			{
				file << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->AverageBall() << "   ";
				for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) 
				{
					file << groups[i]->students[j]->marks[h] << " ";
				}
				file << endl;
			}
			file << endl;
		}
	}file.close();
}

void Deanery::PrintData()
{
	cout << "The number of students is  " << allstudents.size() << endl;
	for (int i = 0; i < groups.size(); i++)
	{
		cout << "In " << groups[i]->title << " " << groups[i]->students.size() << " people. " << " The averade groups mark - " << groups[i]->AverageGroup() << endl;
		cout << "Head: " << groups[i]->head->fio << endl;
		for (int j = 0; j < groups[i]->students.size(); j++)
		{
			cout << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->AverageBall() << "   ";
			for (int h = 0; h < groups[i]->students[j]->marks.size(); h++)
			{
				cout << groups[i]->students[j]->marks[h] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << "Students statistics:" << endl;
	for (int i = 0; i < StatStud.size(); i++)
	{
		cout << StatStud[i].second << "-" << StatStud[i].first << endl;
	}

	cout << "Groups statistics:" << endl;
	for (int i = 0; i < StatGroup.size(); i++)
	{
		cout << StatGroup[i].second << "-" << StatGroup[i].first << endl;
	}
}

int Deanery::GetStudentsNumber() 
{
	return allstudents.size();
}