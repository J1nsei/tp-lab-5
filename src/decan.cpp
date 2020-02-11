#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "decan.h"
#include "group.h"
#include "student.h"


Decan::Decan(std::string Fstudents, std::string Fgroup)
{
	fstreamStudent = std::move(Fstudents);
	fstreamGroup = std::move(Fgroup);
}

void Decan::addStudent()
{
	std::ifstream fStudent(fstreamStudent);
	std::string name;
	int ID = 1;
	while (std::getline(fStudent, name))
	{
		student.push_back(new Student(name, ID));
		ID++;
	}
	fStudent.close();
}

void Decan::addGroup()
{
	std::ifstream fGroup(fstreamGroup);
	std::string groupName;
	while (std::getline(fGroup, groupName))
	{
		group.push_back(new Group(groupName));
	}
	fGroup.close();

	for (int i = 0; i < group.size(); i++)
	{
		for (unsigned int j = i * (student.size() / group.size()); j < (i + 1) * (student.size() / group.size()); j++)
		{
			student[j]->add(group[i]->groupName);
			group[i]->addStudent(student[j]);
		}
	}
}


void Decan::setMarks()
{
	int mark;
	for (auto& student : student)
	{
		mark = std::rand() % 10 + 1;
		student->setMarks(mark);
	}
}


void Decan::changeGroup(Student* student, const std::string& groupName)
{
	for (auto& curGroup : group)
	{
		if (curGroup->groupName == groupName)
		{
			std::string thisGroup = student->group;
			for (auto& group : group)
			{
				if (group->groupName == thisGroup)
				{
					group->kickStudent(student->ID);
				}
			}
			student->add(curGroup->groupName);
			curGroup->addStudent(student);
		}
	}
}


void Decan::kickStudent()
{
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i]->getAverage() < 4)
		{
			std::string groupName = student[i]->group;
			for (auto& curGroup : group)
			{
				if (curGroup->groupName == groupName)
				{
					curGroup->kickStudent(student[i]->ID);
					student.erase(student.begin() + i);
					i--;
				}
			}
		}
	}
}


void Decan::setHead()
{
	for (auto& group : group)
	{
		group->setHead();
	}
}


void Decan::printGroup()
{
	for (auto& group : group)
	{
		std::cout << "Group name -" << group->groupName << std::endl;
		std::cout << "Students in group" << group->student.size() << std::endl;
		std::cout << "Group headmaster - " << group->head->name << std::endl<<std::endl;

		for (auto& student : group->student)
		{
			std::cout << student->name << " "; 
			for (int mark : student->marks)
			{
				std::cout << mark << ",";
			}
			std::cout << std::endl;
			std::cout << "Average is - " << student->getAverage << " "<<std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << "Average students mark - ";
	for (auto& pair : studentsMMark)
	{
		std::cout << pair.second << " " << pair.first << std::endl;
	}

	std::cout << "Average groups mark - ";
	for (auto& pair : groupMMark)
	{
		std::cout << pair.second << " " << pair.first << std::endl;
	}
}


int Decan::countStudents()
{
	return student.size();
}