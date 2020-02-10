#include "Group.h"
#include "Student.h"
#include <vector>
#include <cstring>
#include <string>
#include <time.h>
using namespace std;

Group::Group(string a)
{
	title = a;
	if (a == "1")
		spec = "PMI";
	if (a == "2")
		spec = "FIL";
	if (a == "3")
		spec = "PR";

}

void Group::AddStudent(Student* a)
{
	students.push_back(a);
	//a->AddGroup(this);
}

void Group::ChooseHead()
{
	srand(time(0));
	int i = rand() % (int)students.size();
	head = students[i];
	//cout << students[i]->fio<< endl;
}
Student* Group::findStudentId(int a)
{
	for (int i = 0; i < (int)students.size(); i++)
	{
		if (students[i]->id == a)
			return students[i];
	}
	return nullptr;
}

double Group::MiddleGroupMark()
{
	double sum = 0;
	if (students.size() == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < (int)students.size(); i++)
		{

			sum +=students[i]->MiddleMark();
			
		}
		
		
		return sum / students.size(); ;
	}

}
void Group::ExStudent(int a)
{
	for (int i = 0; i < (int)students.size(); i++)
	{
		if (students[i]->id == a)
		{
				students.erase(students.begin() + i);
				
		}
	}
	/*for (int i = 0; i < (int)students.size(); i++)
	{
		cout << students[i]->fio << " ";
	}*/

}