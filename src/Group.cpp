#include "Group.h" //fix
#include <vector>


Group::Group(string title_)
{
	title = title_;
};

void Group::AddStudent(Student *student_) 
{
	students.push_back(student_);
}

Student* Group::HeadElection() 
{
	if (students.size() > 0) 
	{
		if (students.size() > 1) 
		{
			int _head = rand() % students.size();
			head = students[_head];
			return head;
		}
		else head = students[0];
		return head;
	}
	else return nullptr;
}

Student* Group::SearchStudent(int id_)
{
	for (int i = 0; i < students.size(); i++) 
	{
		if (students[i]->id == id_) 
		{
			return students[i];
		}
	}
}

double Group::AverageGroup()
{
	double sum = 0;
	for (int i = 0; i < students.size(); i++)
	{
		sum += students[i]->AverageBall();
	}
	return sum / students.size();
}

void Group::DeleteStudent(int id_)
{
	for (int i = 0; i < students.size(); i++) 
	{
		if (students[i]->id == id_) 
		{
			if (students[i] == head) 
			{
				students.erase(students.begin() + i);
				HeadElection();
			}
			else
			{
				students.erase(students.begin() + i);
			}
			
		}
	}
}

int Group::GetSize()
{
	return students.size();
}