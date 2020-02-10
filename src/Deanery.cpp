#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Deanery.h"

static int id_ = 0;


Deanery::Deanery(string output)
{
	ifstream input(output);
	string str;
	while (getline(input, str, '\n'))
	{
		string fio_;
		string title_;
		stringstream inputStream(str);
		getline(inputStream, fio_, ';');
		getline(inputStream, title_, '\n');
		
		Student* student = make_student(fio_);

		if (find_group_title(title_)!= nullptr)
		{
			Group* group = find_group_title(title_);
			group->add_student_(student);
		
		}
		else
		{
			Group* group = make_group(title_);
			group->add_student_(student);
			add_group(group);
		}
			
	}
	input.close();
}

Group* Deanery::make_group(string title_)
{
	Group* group = new Group(title_);
	return group;
}


bool Deanery::add_group(Group* group_)
{
	if (!find_group(group_))
	{
		groups.push_back(group_);
		return true;
	}
	else
	{
		return false;
	}
}

bool Deanery::add_student(Group* group_, Student* student_)
{
	if (!find_student(student_))
	{
		group_->add_student_(student_);
		return true;
	}
	else
	{
		return false;
	}
}

Student* Deanery::make_student(string fio_)
{
	Student* student = new Student(id_, fio_);
	id_++;
	return student;
}

void Deanery::add_marks()
{
	srand(time(NULL));
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			student->marks.push_back(1 + rand() % 10);
		}
	}
}

void Deanery::add_mark(int id_, int mark_)
{
	Student*student = find_student(id_);
	if (student != nullptr)
	{
		student->set_mark(mark_);
	}
}

void Deanery::add_mark(string fio_, int mark_)
{
	Student*student = find_student(fio_);
	if (student != nullptr)
	{
		student->set_mark(mark_);
	}
}

void Deanery::add_mark(Student* student_, int mark_)
{
	if (find_student(student_))
	{
		student_->set_mark(mark_);
	}
}


float Deanery::get_average_mark_student(string fio_)
{
	Student* student = find_student(fio_);
	if (student != nullptr)
	{
		return student->average_mark();
	}
	else
	{
		return 0;
	}
}

float  Deanery::get_average_mark_student(int id_)
{
	Student* student = find_student(id_);
	if (student != nullptr)
	{
		return student->average_mark();
	}
	else
	{
		return 0;
	}
}

float  Deanery::get_average_mark_Group(string title_)
{
	Group* group = find_group_title(title_);
	if (group != nullptr)
	{
		return group->average_score_in_group();
	}
	else
	{
		return 0;
	}
}

bool Deanery::transmit_student(Group *output, Group *input, int id_)
{
	if (output == input)
	{
		return false;
	}
	if (!output->student_in_group(id_))
	{
		return false;
	}
	Student* student = find_student(id_);
	if (student != nullptr && find_group(output) && find_group(input))
	{
		output->remove_student_(id_);
		input->add_student_(student);
		return true;
	}
	else
	{
		return false;
	}

}

bool Deanery::transmit_student(Group *input, int id_)
{
	if (input->student_in_group(id_))
	{
		return false;
	}
	Student* student = find_student(id_);
	if (student != nullptr && find_group(input))
	{
		student->get_group()->remove_student_(id_);
		input->add_student_(student);
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Deanery::transmit_student(Group *output, Group *input, Student* student_)
{
	if (output == input)
	{
		return false;
	}
	if (!output->student_in_group(id_))
	{
		return false;
	}
	if (find_student(student_) && find_group(output) && find_group(input))
	{
		output->remove_student_(id_);
		input->add_student_(student_);
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Deanery::transmit_student(Group *input, Student* student_)
{
	if (input->student_in_group(id_))
	{
		return false;
	}
	if (find_student(student_) && find_group(input))
	{
		student_->get_group()->remove_student_(id_);
		input->add_student_(student_);
		return true;
	}
	else
	{
		return false;
	}
}
bool Deanery::transmit_student(Group *output, Group *input, string fio_)
{
	if (output == input)
	{
		return false;
	}
	if (!output->student_in_group(id_))
	{
		return false;
	}
	Student* student = find_student(fio_);
	if (student != nullptr && find_group(output) && find_group(input))
	{
		output->remove_student_(fio_);
		input->add_student_(student);
		return true;
	}
	else
	{
		return false;
	}
}

bool Deanery::transmit_student(Group *input, string fio_)
{
	if (input->student_in_group(id_))
	{
		return false;
	}
	Student* student = find_student(fio_);
	if (student != nullptr && find_group(input))
	{
		student->get_group()->remove_student_(fio_);
		input->add_student_(student);
		return true;
	}
	else
	{
		return false;
	}
}

void Deanery::remove_student()
{
	vector<int> lis;
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			if (student->average_mark() < 4)
			{
				lis.push_back(student->get_id());
			}
		}
		for (int id_ : lis)
		{
			Student* student = find_student(id_);
			group->remove_student_(id_);
			delete student;
		}
	}
}

void Deanery::choose_head_()
{
	for (Group* group : groups)
	{
		group->choose_head();
	}
}

void Deanery::out_data_in_consol()
{
	cout << "\n Общие сведения:" << endl << "\n";
	for (Group* group : groups)
	{
		cout << "\t Название группы: " << group->get_title() << "\n";
		cout << "\t Специальность: " << group->get_spec() << "\n";
		cout << "\t Количество студентов: " << group->students.size() << "\n";
		cout << "\t Староста: " << group->get_head() << "\n";
		cout << "\t Средний бал в группе: " << group->average_score_in_group() << "\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		for (Student* student : group->students)
		{
			if (student->get_id()<10)
				cout << "\t ID:  " << student->get_id() << ";\t Средний балл ~ " << student->average_mark() << ";\t ФИО : " << student->get_fio() << "\n";
			else
				cout << "\t ID: " << student->get_id() << ";\t Средний балл ~ " << student->average_mark() << ";\t ФИО : " << student->get_fio() << "\n";
		}
	cout << "-------------------------------------------------------------------------------------------" << "\n";
	}
}

void Deanery::save_data(string input)
{
	ofstream output;
	output.open(input);
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			output << student->get_fio() << ";" << group->get_title() << endl;
		}
	}
	output.close();
}

Student* Deanery::find_student(string fio_)
{
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			if (student->get_fio() == fio_)
			{
				return student;
			}
		}
	}
	return nullptr;
}

Student* Deanery::find_student(int id_)
{
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			if (student->get_id() == id_)
			{
				return student;
			}
		}
	}
	return nullptr;
}

bool Deanery::find_student(Student* student_)
{
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			if (student == student_)
			{
				return true;
			}
		}
	}
	return false;
}

Group* Deanery::find_group_title(string title_)
{
	for (Group* group : groups)
	{
		if (group->get_title() == title_)
		{
			return group;
		}
	}
	return nullptr;
}

Group* Deanery::find_group_spec(string spec_)
{
	for (Group* group : groups)
	{
		if (group->get_spec() == spec_)
		{
			return group;
		}
	}
	return nullptr;
}

bool Deanery::find_group(Group* group_)
{
	for (Group* group : groups)
	{
		if (group == group_)
		{
			return true;
		}
	}
	return false;
}

Group* Deanery::find_student_in_group(int id_)
{
	for (Group*group : groups)
	{
		if (group->student_in_group(id_))
		{
			return group;
		}
	}
	return nullptr;
}
Group* Deanery::find_student_in_group(string fio_)
{
	for (Group*group : groups)
	{
		if (group->student_in_group(fio_))
		{
			return group;
		}
	}
	return nullptr;
}
Group* Deanery::find_student_in_group(Student* student_)
{
	for (Group*group : groups)
	{
		if (group->student_in_group(student_))
		{
			return group;
		}
	}
	return nullptr;
}

string Deanery::small_check()
{
	for (Group* group : groups)
	{
		for (Student* student : group->students)
		{
			if (student->get_group() != group)
			{
				string err = "Ошибка в указателе группы у студента: ";
				err = err + student->get_fio();
				return err;
			}
			if (student->marks.empty())
			{
				add_marks();
			}
		}
		if (group->head == nullptr)
		{
			group->choose_head();
		}
	}
	return "Теперь все норм";
}
