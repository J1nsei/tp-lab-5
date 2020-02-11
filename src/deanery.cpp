#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "student.h"
#include "group.h"
#include "deanery.h"


void Deanery::elect_heads()
{
	for (Group* group : groups)
	{
		group->elect_head();
	}
}

void Deanery::set_marks(unsigned int num)
{
	srand(time(NULL));
	for (Group* group : this->groups)
	{
		for (Student* student : group->get_students())
		{
			for (int i = 0; i < num; i++)
			{
				student->add_mark(rand() % 11);
			}
		}
	}
}

std::vector<std::string> split(const std::string& s, char del)
{
	std::vector<std::string> words;
	std::string word;
	std::istringstream stream(s);
	while (getline(stream, word, del))
		words.push_back(word);
	return words;
}

Deanery::Deanery()
{
}

void Deanery::add_groups(std::string names_input, std::string groups_input)
{

	std::ifstream fin;
	fin.open(groups_input, std::ios::in);
	std::string buf;
	std::vector <std::string> data;
	while (getline(fin, buf))
	{
		data = split(buf, ':');
		groups.push_back(new Group(data[0], data[1]));
	}
	fin.close();


	fin.open(names_input, std::ios::in);
	while (getline(fin, buf))
	{
		bool flag_done = 0;
		int number_group = 0;
		data = split(buf, ':');
		Student* student = new Student(data[0], d_id);

		
		for (int i = 0; i < groups.size(); i++)
		{
			if (groups[i]->get_title() == data[1])
			{
				flag_done = 1;
				number_group = i;
			}
		}
		if (!flag_done)
		{
			Group* group = new Group(data[1], "");
			groups.push_back(group);
			number_group = groups.size() - 1;
		}
		groups[number_group]->add_student(student);
		student->set_group(groups[number_group]);
		d_id++;
	}
	fin.close();
}



void Deanery::get_stat() const
{
	for (Group* group : groups)
	{
		group->get_average_group();
		std::vector<Student*> students = group->get_students();
		unsigned int mark_best = 0;
		unsigned int id_best = 0;
		unsigned int mark_worst = 10;
		unsigned int id_worst = 0;
		for (int i = 0; i < students.size(); i++)
		{
			if ((students[i]->get_average()) > mark_best)
			{
				id_best = i;
			}
			if ((students[i]->get_average()) < mark_worst)
			{
				id_worst = i;
			}
		}
		std::cout << "The most successful student : " << students[id_best]->get_name() << " = " << students[id_best]->get_average() << std::endl;
		std::cout << "The worst student : " << students[id_worst]->get_name() << " = " << students[id_worst]->get_average() << std::endl;
	}
}

void Deanery::change_group(std::string fio, std::string prev_group, std::string curr_group)
{
	Group* group_prev = nullptr;
	Group* group_curr = nullptr;
	for (Group* group : groups)
	{
		if (group->get_title() == prev_group) group_prev = group;
		if (group->get_title() ==  curr_group) group_curr = group;
	}
	Student* stud = group_prev->find(fio);

	if (group_prev != nullptr && group_curr != nullptr)
	{
		group_prev->allocation(stud);
		group_curr->add_student(stud);
	}
}

void Deanery::allocations()
{
	for (Group* group : groups)
	{
		for (Student* student : group->get_students())
		{
			if (student->get_average() < 3.5)
			{
				group->allocation(student);
			}
		}
	}
}

void Deanery::save_data(std::string file_names, std::string file_groups) const
{
	std::ofstream file;
	file.open(file_names, std::ios::out);
	if (file.is_open())
	{
		for (Group* group : groups)
		{
			for (Student* student : group->get_students())
			{
				file << student->get_name() << " : " << group->get_title() << std::endl;
			}
		}
	}
	file.close();

	file.open(file_groups, std::ios::out);
	if (file.is_open())
	{
		for (Group* group : groups)
		{
			file << group->get_title() << " : " << group->get_spec() << std::endl;
		}
	}
	file.close();
}

