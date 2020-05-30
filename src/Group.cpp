#include "Group.h"

Group::Group(string title_)
{
	title = title_;
	head = nullptr;
	students = {};
	if (title_ == "20ÏÌÈ-1" || title_ == "20ÏÌÈ-2")
		spec = "Ïğèìàò";
	else if (title_ == "20ÏÈ-1" || title_ == "20ÏÈ-2")
		spec = "Èíæèğ";
	else if (title_ == "20ÓÁ-1" || title_ == "20ÓÁ-2")
		spec = "Ìàíàãåğ";
	else if (title_ == "20İ-1" || title_ == "20İ-2")
		spec = "Òîğãàø";
}

void Group::add_student_(Student* student_)
{
	if (!student_in_group(student_))
	{
		students.push_back(student_);
		student_->change_group(this);
	}
}

void Group::choose_head()
{
	float max = 0;
	Student* head_ = nullptr;
	for (Student* student : students)
	{
		if (student->average_mark() >= max)
		{
			head_ = student;
			max = student->average_mark();
		}
	}
	head = head_;
}

bool Group::student_in_group(Student* student_)
{
	for (Student* student : students)
	{
		if (student == student_)
			return true;
	}
	return false;
}

bool Group::student_in_group(int id_)
{
	for (Student* student : students)
	{
		if (student->get_id() == id_)
			return true;
	}
	return false;
}

bool Group::student_in_group(string fio_)
{
	for (Student* student : students)
	{
		if (student->get_fio() == fio_)
			return true;
	}
	return false;
}

float Group::average_score_in_group()
{
	float sum = 0;
	if (students.size() != 0)
	{
		for (Student* student : students)
		{
			sum += student->average_mark();
		}
		return sum / students.size();
	}
	else
	{
		return 0;
	}
}

bool Group::remove_student_(int id_)
{
	int index = -1;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->get_id() == id_)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		students.erase(students.begin() + index);
		return true;
	}
	else
	{
		return false;
	}
}


bool Group::remove_student_(string fio_)
{
	int index = -1;
	for (Student* student : students)
	{
		if (student->get_fio() == fio_)
		{
			index++;
			break;
		}
	}
	if (index != -1)
	{
		students.erase(students.begin() + index);
		return true;
	}
	else return false;
}

/*
bool Group::remove_student_(Student* student)
{
	int index = -1;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->get_fio() == student->get_fio())
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		students.erase(students.begin() + index);
		return true;
	}
	else return false;
}
*/

string Group::get_title()
{
	return title;
}

string Group::get_spec()
{
	return spec;
}

string Group::get_head()
{
	if (head != nullptr)
	{
		return head->get_fio();
	}
	else
	{
		return "Íåòó";
	}
}
