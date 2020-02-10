#include <algorithm>
#include <numeric>
#include "Student.h"

Student::Student(int id_, string fio_)
{
	id = id_;
	fio = fio_;
	group = nullptr;
	marks = {};
}

void Student::change_group(Group * new_group)
{
	group = new_group;
}

void Student::set_mark(int mark_)
{
	marks.push_back(mark_);
}

float Student::average_mark()
{
	if (marks.size() != 0)
	{
		return accumulate(begin(marks), end(marks), 0) / marks.size();
	}
	else
	{
		return 0;
	}
}

int Student::get_id()
{
	return id;
}

string Student::get_fio()
{
	return fio;
}

Group * Student::get_group()
{
	return group;
}
