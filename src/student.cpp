#include "student.h"
#include "group.h"
#include "dean.h"

Student::Student(unsigned int id, std::string fio) {
	this->id = id;
	this->fio = fio;
}

void Student::add_group(Group* group) {
	group->students.push_back(this);
	this->group = group;
}

void Student::add_mark(int mark) {
	if ((1 <= mark) && (mark <= 5))
	{
		this->marks.push_back(mark);
	}
}

float Student::average() {
	float sum = 0;
	for (auto x : this->marks)
		sum += x;
	return (float)(sum / this->marks.size());
}

void Student::get_marks()
{
	for (auto i : this->marks)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int Student::get_id()
{
	return this->id;
}