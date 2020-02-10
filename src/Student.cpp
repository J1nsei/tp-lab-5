#include "Student.h"
#include <vector>
#include <cstring>
#include <string>
using namespace std;




Student::Student()
{
	
}
Student::Student(int a, string name,string gr)
{
	id = a;
	fio = name;
	group = gr;
}

void Student::AddGroup(string a)
{
	group = a;
}

void Student::AddMark(int a)
{
	marks.push_back(a);
	
}

double Student::MiddleMark()
{
	int sum = 0;
	for (int i = 0; i < marks.size(); i++)
		sum = sum + marks[i];
	
	return (double)sum / (double)marks.size();
}

