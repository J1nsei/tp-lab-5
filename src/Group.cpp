#include "Group.h"




Group::Group(string title)
{
	this->title = title;
	this->head = NULL;
}

Group::~Group()
{
	
}


Group::Group()
{
	this->head = NULL;
}


string Group::getTitle()
{
	return title;
}
vector<Student*> Group::getStudens()
{
	return students;
}
Student* Group::getHead()
{
	return head;
}
Student* Group::getStudentById(int id)
{
	for (Student* student : students)
	{
		if (student->getId() == id)
			return student;
	}
	return NULL;
}
Student* Group::getStudentByName(string fio)
{

	for (Student* student : students)
	{
		if (student->getFio() == fio)
			return student;
	}
	return NULL;
}
double Group::getMeatMark()
{
	double meat = 0;
	for (Student* student : students)
	{
		meat += student->getMean();
	}
	return meat / students.size();
}
void Group::addStudent(class Student* student)
{
	students.push_back(student);
}
Student* Group::chouseNewHead()
{
	srand(time(0));
	int numb = rand() % students.size();
	head = students[numb];
	return head;
}
void Group::killStudent(Student* student)
{
	killStudent(student->getId());
}
void Group::killStudent(int id)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getId() == id)
		{
			delete(&(students[i]));
			students.erase(students.begin() +i);
			return;
		}
	}
}
void Group::killStudent(string fio)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->getFio() == fio)
		{
			delete(&(students[i]));
			students.erase(students.begin() + i);
			return;
		}
	}
}