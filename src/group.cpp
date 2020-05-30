#pragma once
#include "group.h"
#include "student.h"
#include "dean.h"


Group::Group(std::string name)
{
	this->name = name;
}

void Group::add_student(Student* st)
{
	st->add_group(this);
	//this->students.push_back(st);
}

Student* Group::set_head()
{
	int head = 0;
	if (this->students.size() > 0)
	{
		if (this->students.size() > 1)
		{
			head = rand() % (this->students.size());
			this->head = this->students[head];
			return this->students[head];
		}
		else
		{
			this->head = this->students[0];
			return this->students[0];
		}
	}
	else
	{
		return nullptr;
	}
}

Student* Group::find_student(unsigned int id, std::string fio)
{
	for (auto i : this->students)
	{
		if ((i->fio == fio) && (i->id == id))
		{
			return i;
		}
	}
}

Student* Group::find_student(unsigned int id)
{
	for (auto i : this->students)
	{
		if (i->id == id)
		{
			return i;
		}
	}
}

Student* Group::find_student(std::string fio)
{
	for (auto i : this->students)
	{
		if (i->fio == fio)
		{
			return i;
		}
	}
}

float Group::average()
{
	float sum = 0;
	for (auto i : this->students)
	{
		sum += i->average();
	}
	return (float)(sum / this->students.size());
}

bool Group::exclude(unsigned int id)
{
	int el = -1;
	bool ready = false;
	bool head = false;
	for (int i = 0; i < this->students.size(); i++)
	{
		if (id == this->students[i]->id)
		{
			el = i;
			ready = true;
			if ((ready) && (this->head == this->students[i]))
			{
				head = true;
			}
		}
	}
	if (ready)
	{
		this->students.erase(this->students.begin() + el);
		if (head)
		{
			this->set_head();
		}
		return ready;
	}
	else
	{
		return ready;
	}
}

bool Group::exclude(std::string fio)
{
	int el = -1;
	bool ready = false;
	for (int i = 0; i < this->students.size(); i++)
	{
		if (fio == this->students[i]->fio)
		{
			el = i;
			ready = true;
		}
	}
	if (ready)
	{
		this->students.erase(this->students.begin() + el);
		return ready;
	}
	else
	{
		return ready;
	}
}
std::string Group::get_name()
{
	return this->name;
}