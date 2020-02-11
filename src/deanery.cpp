
#include "Student.h"
#include "group.h"
#include "deanery.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
//#include <ifstream>
#include <random>

Deanery::Deanery()
{
	//groups = vector < Group* >() ;
	//int id = 0;
}

void Deanery::make_students(int id, string fio, Group* group)
{
	Student* student = new Student(id, fio);
	group->add_student(student);
}

Group* Deanery::make_groups(string title, string spec)
{
	Group* new_group = new Group(title, spec);
	groups.push_back(new_group);
	return new_group;
}

void Deanery::add_mark(Group* group, string student, int mark)
{
	/*void Deanery::add_mark(int mark)
	srand(time(0));
	for (auto group : groups)
	{
		for (Student* student : group->getStudents())
		{
			for (int m = 0; m < mark; m++)
			{
				student->set_mark(mark);
			}
		}
	}*/
	Student* stud = group->find_student_fio(student);
	stud->set_mark(mark);
}

float Deanery::get_average_mark_student(Group* group, string student)
{
	Student* stud = group->find_student_fio(student);
	return stud->average_mark();
}

float Deanery::get_average_mark_group(Group* group)
{
	return group->average_mark();
}

void Deanery::change_group_for_student(string fio, Group* old_group, Group* new_group)
{
	Student* student = old_group->find_student_fio(fio);
	old_group->delete_student(student);
	student->set_group(new_group);
	new_group->add_student(student);
}

void Deanery::delete_student_for_poor_grades(Group* group)
{
	for (auto student : group->getStudents())
	{
		if (student->average_mark() < 3.0)
		{
			group->delete_student(student);
		}
	}
}

void Deanery::save_new_data()
{
	ofstream file("Deanery.txt");
	for (auto group : groups)
	{
		file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		file << "Название специальности: " << group->getSpec() << " " << endl;
		file << "Название группы: " << group->getTitle() << " " << endl;
		if (group->getHead() == nullptr)
		{
			file << "They have not head!" << endl;
		}
		else
		{
			file << "Староста: " << group->getHead()->getFio() << endl;
		}
		file << "**********************************************" << endl;
		for (auto student : group->getStudents())
		{
			/*string f = student->getFio();
			int i = student->getId();*/
			file << "ID: " << student->getId() << "\tФИО: " << student->getFio() << endl;
			file << "Средний балл: " << student->average_mark() << endl;
			for (auto mark : student->getMarks())
			{
				
				file << "Список оценок: " << mark << " " << endl;
			}
			file << endl;
		}
	}
}

void Deanery::make_head(Group* group)
{
	group->choose_head();
}

void Deanery::print_data()
{
	for (auto group : groups)
	{
		cout << endl << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Название специальности: " << group->getSpec() << " " << endl;
		cout << "Название группы: " << group->getTitle() << " " << endl;
		if (group->getHead() == nullptr)
		{
			cout << "They have not head!" << endl;
		}
		else
		{
			cout << "Староста: " << (group->getHead())->getFio() << endl;
		}
		cout << "**********************************************" << endl;
		for (auto student : group->getStudents())
		{
			/*string f = student->getFio();
			int i = student->getId();*/
			cout << "ID: " << student->getId() << "\tФИО: " << student->getFio() << endl;
			cout << "Средний балл: " << student->average_mark() << endl;
			for (auto mark : student->getMarks())
			{
				cout << "Список оценок: " << mark << " " << endl;
			}
			cout << endl;
		}
	}
}
