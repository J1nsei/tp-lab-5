#include "Student.h"


using namespace std;



Student::Student(int id1, const string& name1, const string& group1) {
	name = name1;
	group = group1;
	id = id1;
}

void Student::add_Group(string group1)
{
	group = group1;
}
void Student::add_Mark(int mark)
{
	marks.push_back(mark);
}
double Student::average_Mark()
{
	double sum = 0;
	for (size_t i = 0; i < marks.size(); i++) {
		sum += marks[i];
	}
	return( sum / marks.size());
}

int Student::get_id()
{
	return id;
}

Student::Student()
{
	id = -1;
	name = "0";
}

void Student::set_id(int new_id)
{
	id = new_id;
}

string Student::get_name()
{
	return name;
}

vector<int> Student::get_marks()
{ 
	return marks; 
}