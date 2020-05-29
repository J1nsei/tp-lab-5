#include"Student.h"
#include"Group.h"

Student::Student(const int& id, const string& fio)
{
	Student::id = id;
	Student::fio = fio;
}

void Student::add_mark(const int& mark)
{
	marks.push_back(mark);
}

double Student::average_mark()
{
	int sum = 0;
	for (int mark : marks)
	{
		sum += mark;
	}
	return sum / (double)marks.size();
}

int Student::get_id()
{
	return id;
}

string Student::get_name()
{
	return fio;
}

void Student::sign_up(Group* gr)
{
	group = gr;
}