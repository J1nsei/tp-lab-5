
#include "deanery.h"
#include "Student.h"
#include "group.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <random>

using namespace std;

vector<string> split(const string & s, char delimiter)
{
	vector<string> Tokens;
	string Token;
	istringstream TokenStream(s);
	while (getline(TokenStream, Token, delimiter))
		Tokens.push_back(Token);
	return Tokens;
}

int main()
{
	system("chcp 1251");

	Deanery* deanery = new Deanery();

	Group * PMI1 = deanery->make_groups("18PMI-1", "Прикладная математика и информатика");
	Group * PMI2 = deanery->make_groups("18PMI-2", "Прикладная математика и информатика");
	Group * PI1 = deanery->make_groups("18PI-1", "Программная инженерия");
	Group * PI2 = deanery->make_groups("18PI-2", "Программная инженерия");
	Group * BI1 = deanery->make_groups("18BI-1", "Бизнес-информатика");
	Group * BI2 = deanery->make_groups("18BI-2", "Бизнес-информатика");
	Group * FL1 = deanery->make_groups("18FL-1", "Филология");
	Group * FL2 = deanery->make_groups("18FL-2", "Филология");

	//deanery->make_students(1, "Колодезев Евсей Эрнестович", PMI1);
	//deanery->make_students(4, "dfjk sdkjf skfdj", PMI2);

	//deanery->print_data();
	//deanery->save_new_data();

	ifstream file("students_with_groups.txt");

	while (!file.eof())
	{
		int id = 1;
		string buf;
		getline(file, buf, '\n');
		vector<string> data = split(buf, ':');
		if (data[1] == "18PMI-1")
		{
			deanery->make_students(id, data[0], PMI1);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(PMI1, data[0], rand() % 10);
			}
		}
		if (data[1] == "18PMI-2")
		{
			deanery->make_students(id, data[0], PMI2);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(PMI2, data[0], rand() % 10);
			}
		}
		if (data[1] == "18PI-1")
		{
			deanery->make_students(id, data[0], PI1);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(PI1, data[0], rand() % 10);
			}
		}
		if (data[1] == "18PI-2")
		{
			deanery->make_students(id, data[0], PI2);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(PI2, data[0], rand() % 10);
			}
		}
		if (data[1] == "18BI-1")
		{
			deanery->make_students(id, data[0], BI1);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(BI1, data[0], rand() % 10);
			}
		}
		if (data[1] == "18BI-2")
		{
			deanery->make_students(id, data[0], BI2);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(BI2, data[0], rand() % 10);
			}
		}
		if (data[1] == "18FL-1")
		{
			deanery->make_students(id, data[0], FL1);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(FL1, data[0], rand() % 10);
			}
		}
		if (data[1] == "18FL-2")
		{
			deanery->make_students(id, data[0], FL2);
			for (int i = 0; i < 10; i++)
			{
				deanery->add_mark(FL2, data[0], rand() % 10);
			}
		}
		id += 1;
	}

	//deanery->print_data();

	deanery->make_head(PMI1);
	deanery->make_head(PMI2);
	deanery->make_head(PI1);
	deanery->make_head(PI2);
	deanery->make_head(BI1);
	deanery->make_head(BI2);
	deanery->make_head(FL1);
	deanery->make_head(FL2);
	
	cout << deanery->get_average_mark_student(PMI1, "Колодезев Евсей Эрнестович") << endl;
	
	cout << deanery->get_average_mark_group(PMI1) << endl;
	
	deanery->change_group_for_student("Колодезев Евсей Эрнестович", PMI1, BI2);

	deanery->delete_student_for_poor_grades(PI1);
	
	deanery->print_data();
	deanery->save_new_data();

	return 0;
}