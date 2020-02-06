#include "Student.h" //fix
#include <vector>

Student::Student(int id_, string fio_)
{
	id = id_;
	fio = fio_;
}

void Student::AddGroup(string group_)
{
	group = group_;
}

void Student::AddMark(int mark)
{
	marks.push_back(mark);
}

double Student::AverageBall()
{
	double sum = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
	}
	return sum / marks.size();
}
