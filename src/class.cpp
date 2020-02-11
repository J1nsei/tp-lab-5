#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "class.h"

// Student---------------------------------------------------------------------------------------------

Student::Student(int id, std::string fio)
{
	this->id = id;
	this->fio = fio;
}

void Student::JoinGroup(Group * group)
{
	this->group = group;
}

void Student::AddMark(int number)
{
	marks.push_back(number);
}

double Student::AvrMark()
{
	double mark = 0;
	int size = marks.size();
	for (int i = 0; i < size; i++)
	{
		mark += marks[i];
	}
	return (mark / size);
}

// Group-------------------------------------------------------------------------------------------------

Group::Group(std::string title)
{
	this->title = title;
}

void Group::JoinGroup(Student *student)
{
	students.push_back(student);
	student->JoinGroup(this);
}

void Group::ChooseLid()
{
	int size = students.size();
	lider = students[rand() % size];
	//printf("%s\n", lider->fio.c_str());
}

int Group::Search(int id)
{
	int size = students.size();
	for (int i = 0; i < size; i++)
	{
		if (students[i]->id == id)
		{
			return i;
		}
	}
	return -1;
}

double Group::AvrMark()
{
	int size = students.size();
	double Sum = 0;
	for (int i = 0; i < size; i++)
	{
		Sum += students[i]->AvrMark();
	}
	return (Sum / size);
}

void Group::Delete(int id)
{
	if (lider->id == id)
	{
		students.erase(students.begin() + Search(id));
		ChooseLid();
	}
	else
		students.erase(students.begin() + Search(id)); 
	//printf("%s", lider->fio.c_str);
}

std::string Group::GetLider()
{
	return (lider->fio);
}

// Deanery-------------------------------------------------------------------------------------------------

void Deanery::CreateSt(std::vector<std::string> fio)
{
	int size = fio.size();

	//printf("Из функции size = %d", size);

	for (int i = 0; i < size; i++)
	{
		Student temp = Student(i+1, fio[i]);
		allstudents.push_back(temp);
		//printf("%s\n", fio[i].c_str());
	}
}

void Deanery::CreateGr(std::string title1, std::string title2, std::string title3)
{
	int size = allstudents.size();
	int i = size / 3;
	Group PMI1(title1);
	Group PMI2(title2);
	Group PMI3(title3);
	int j = 0;
	for (j; j < i; j++)
	{
		PMI1.students.push_back(&allstudents[j]);
		//printf("Группа = %s\n", allstudents[j].group->title.c_str());
	}
	for (j; j < i*2; j++)
	{
		PMI2.students.push_back(&allstudents[j]);
	}
	for (j; j < size; j++)
	{
		PMI3.students.push_back(&allstudents[j]);
	}
	groups.push_back(PMI1);
	groups.push_back(PMI2);
	groups.push_back(PMI3);
	for (i = 0; i < 3; i++)
	{
		size = groups[i].students.size();
		for (j = 0; j < size; j++)
		{
			groups[i].students[j]->group = &groups[i];
		}
	}
}

void Deanery::AddMarks()
{	
	int size = 0;
	for (int i = 0; i < 3; i++)
	{
		size = groups[i].students.size();
		for (int j = 0; j < size; j++)
		{
			groups[i].students[j]->AddMark(rand() % 10 + 1);
		}
	}
}

void Deanery::Statictic(FILE *list)
{
	int size = 0;
	for (int i = 0; i < 3; i++)
	{
		size = groups[i].students.size();
		fprintf(list, "\nГруппа PMI%d\nСредняя оценка в группе - %f\nСписок студентов: количество студентов = %d\n\nСтароста - %s\n\n", i + 1, groups[i].AvrMark(), size, groups[i].lider->fio.c_str());
		for (int j = 0; j < size; j++)
		{
			fprintf(list, "id = %d %s - %f id = %d\n", groups[i].students[j]->id, groups[i].students[j]->fio.c_str(), groups[i].students[j]->AvrMark());
		}
	}
}

void Deanery::ChangeGr(int id, std::string title)
{
	int temp;
	for (int i = 0; i < 3; i++)
	{
		temp = groups[i].Search(id);  //ищем текущую группу студента
		if (temp != -1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (groups[j].title == title) //ищем группу с заданным названием
				{
					groups[j].JoinGroup(groups[i].students[temp]);  
					groups[i].Delete(id);
					return;
				}
			}
		}
	}
}

void Deanery::DeleteSt(int id)
{
	int temp;
	for (int i = 0; i < 3; i++)
	{
		temp = groups[i].Search(id);
		if (temp != -1)
		{
			groups[i].Delete(id);
			return;
		}
	}
}

void Deanery::SaveData(FILE *students)
{
	int size = 0;
	for (int i = 0; i < 3; i++)
	{
		size = groups[i].students.size();
		for (int j = 0; j < size; j++)
		{
			fprintf(students, "%s\n", groups[i].students[j]->fio.c_str());
		}
	}
}

void Deanery::ChooseLid()
{
	for (int i = 0; i < 3; i++)
	{
		groups[i].ChooseLid();
	}
}

void Deanery::about()
{
	int size = 0;
	for (int i = 0; i < 3; i++)
	{
		size = groups[i].students.size();
		printf("\nГруппа PMI%d\nСредняя оценка в группе - %f\nСписок студентов: количество студентов = %d\n\nСтароста - %s\n\n", i + 1, groups[i].AvrMark(), size, groups[i].lider->fio.c_str());
		for (int j = 0; j < size; j++)
		{
			printf("id = %d %s - %f id = %d\n", groups[i].students[j]->id, groups[i].students[j]->fio.c_str(), groups[i].students[j]->AvrMark());
		}
	}
}

std::string Deanery::GroupName(int number)
{
	return (groups[number].title);
}