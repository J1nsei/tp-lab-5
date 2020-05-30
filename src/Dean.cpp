#include"Dean.h"
#include"Group.h"
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>

vector<string>  split(const string s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

Deanery::Deanery()
{
	groups.push_back(new Group("1"));
	groups.push_back(new Group("2"));
	groups.push_back(new Group("3"));
}

void Deanery::CreateGroup()
{
	ifstream file("FIOgroup.txt");
	system("chcp 65001");
	int idD=0;
	vector<string>data;
	while (!file.eof())
	{
		string buf;
		getline(file, buf, '\n');
		data = split(buf, ':');
		for (auto& check : groups)
		{
			if (check->title == data[1])
			{

				check->AddStudent(new Student(idD, data[0],data[1]));
				idD++;

				
				 

			}

		}
		
		
	}
	

}


void Deanery::AddStudentMark()
{
	srand(time(0));
	int a, b;
	for(auto& check : groups)
	  for (int i = 0; i <(check->students).size(); i++)
	  {
		a = rand() % 5;
		b = rand() % 10 + 5;
		(check->students[i])->AddMark(rand() % (b - a));


	  }

}

void Deanery::StatisticGroup()
{
	for (int i = 0; i < groups.size(); i++)
		cout << groups[i]->title <<"    "<< groups[i]->MiddleGroupMark() << endl;
}


void Deanery::ReChooseHeaders(string groupName)
{
	for (int i = 0; i < groups.size(); i++)
	{
		if (groups[i]->title == groupName)
		{
			groups[i]->ChooseHead();
			cout << (groups[i]->head) ->fio << endl;
		}
	}
}

void Deanery::DeductStudents()
{
	
	for (auto& check : groups)
	for (int i = 0; i < (check->students).size(); i++)
	{
		if ((check->students[i])->MiddleMark() < 4)
		{
			check->ExStudent((check->students[i])->id);
			

		}
	}

	
}

void Deanery::Console()
{
	for (auto& check : groups)
	{
		cout << " GROUP title  " << check->title << endl;
		cout << " GROUP spec   " << check->spec << endl;
		cout << " GROUP head   " << (check->head)->fio << endl;
		cout << '\n';
		for (int i = 0; i < (check->students).size(); i++)
		{
			cout << endl; cout << endl;
			cout << " FIO   " << (check->students[i])->fio << endl;
			cout << " ID   " << (check->students[i])->id << endl;
			cout << "marks  ";
			for (int k = 0; k < ((check->students[i])->marks).size(); k++)
				cout << (check->students[i])->marks[k] << ' ';


		}
		cout <<endl;
		cout << '\n';
		cout << '\n';
		cout << '\n';
	}


	

}


void Deanery::ReplaceStudent(int name, string groupnamefrom,string groupnameto)
{
	system("chcp 65001");
	cout << (groups[0]->students).size() << endl;
	cout << (groups[1]->students).size() << endl;
	cout << (groups[2]->students).size() << endl;
	
	Student* tmp=new Student();


	for (auto check : groups)
	{
		if (check->title == groupnamefrom)
		{
			tmp = check->findStudentId(name);
			check->ExStudent(name);
			break;
		}
	}
	for (auto check : groups)
	{
		if (check->title == groupnameto)
		{
			
			check->AddStudent(tmp);
			break;
		}
	}
	
	cout << (groups[0]->students).size() << endl;
	cout << (groups[1]->students).size() << endl;
	cout << (groups[2]->students).size() << endl;

	

	
}


