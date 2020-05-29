#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <random>
#include"Deanery.h"
#include"Group.h"

using namespace std;

void Deanery::create_student(const string& name, const string& title)
{
	int new_id = ++last_free_id;
	Student* new_stud = new Student(new_id, name);
	Group* destin_group = find_group(title);
	destin_group->add(new_stud);
}

void Deanery::create_group(const string& title, const string& spec)
{
	Group* new_group = new Group(title, spec);
	groups.push_back(new_group);
}

void Deanery::create_groups_f(const string& fname)
{
	
	ifstream file(fname);
	int id = last_free_id;
	vector<string> names;
	while (!file.eof()) 
	{
		string buf_fio{}, buf_group_name{}, info_line{}, spec_name{};
		int cur_pos = 0, last_pos = cur_pos;

		getline(file, info_line);

		for (cur_pos = last_pos; info_line[cur_pos] != ','; ++cur_pos) {}
		buf_fio.append(info_line, last_pos, cur_pos - last_pos);
		
		last_pos = cur_pos += 2;
		for (; info_line[cur_pos] != ','; ++cur_pos) {}
		buf_group_name.append(info_line, last_pos, cur_pos - last_pos);
		
		last_pos = cur_pos += 2;
		for (cur_pos; info_line[cur_pos] != '\n' && info_line[cur_pos] != '\0'; ++cur_pos) {}
		spec_name.append(info_line, last_pos, cur_pos - last_pos);
		bool flag = false;
		for (string name : names)
		{
			if (name == buf_group_name) 
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			Group* gr = find_group(buf_group_name);
			Student* new_stud = new Student(id, buf_fio);
			new_stud->sign_up(gr);
			gr->add(new_stud);
		}
		else {
			names.push_back(buf_group_name);
			Group* new_gr = new Group(buf_group_name, spec_name);
			groups.push_back(new_gr);
			Student * new_stud = new Student(id, buf_fio);
			new_gr->add(new_stud);
			new_stud->sign_up(new_gr);
		}
		
		id++;
	}
	last_free_id = id;
	file.close();
}

void Deanery::print_marks()
{
	cout << "GROUPS" << endl;
	for (Group* gr : groups)
	{
		cout << "GROUP: "  << gr->title << "\n" << "STUDENTS: " << endl;
		int i = 1;
		for (Student* st : gr->students) 
		{
			cout << i << ". "<< st->fio << " ID: " << st->id << " MARKS: ";
			for (int mark : st->marks)
			{
				cout << mark << " ";
			}
			cout << endl;
			i++;
		}
		cout << endl;
	}
	cout << endl;
}


void Deanery::print_statistics()
{
	cout << "STATISTICS" << endl;
	cout << "AVERAGE BALL AMONG ALL GROUPS: " << average_ball_all() << endl;
	cout << "TOTAL NUMBER OF STUDENTS: " << total_num_of_stud() << endl << endl;
	for (Group* group : groups)
	{
		cout << "GROUP: " << group->title << endl;
		if (group->head != nullptr)
		{
			cout << "GROUP HEAD: " << group->head->fio;
		}
		cout << endl;
		cout << "AVERAGE BALL IN GROUP: " << group->average_ball() << endl;
		for (size_t i = 0; i < group->students.size(); ++i)
		{
			cout << i + 1 << ". " << group->students[i]->fio << "; ID: " << group->students[i]->id << "; AVERAGE BALL: " << group->students[i]->average_mark() << endl;
		}
		cout << endl;
	}
	cout << endl;
}


void Deanery::rand_marks()
{
	random_device rd;
	mt19937 mersenne(rd());
	for (Group* gr : groups)
	{
		unsigned rand_value = 11;
		for (Student* stud : gr->students)
		{
			stud->marks.push_back(mersenne() % rand_value);
		}
	}
}


double Deanery::average_ball_all()
{
	double sum = 0;
	for (Group* group : groups)
	{
		sum += group->average_ball();
	}
	return sum / groups.size();
}


Group* Deanery::find_group(const string& title)
{
	for (Group* group : groups)
	{
		if (group->title == title)
		{
			return group;
		}
	}
	throw "No groups with such a title";
}


void Deanery::transfer(const int& id, const string& origin_group, const string& destination_group)
{
	Group* or_group = find_group(origin_group), *dest_group = find_group(destination_group);
	Student* stud = or_group->find_id(id);
	expel(origin_group, id);
	dest_group->add(stud);
	
}



void Deanery::expel(const string& title, const int& id)
{
	Group* group = find_group(title);
	Student* stud = group->find_id(id);
	group->expel(stud);
	if (group->head != nullptr)
	{
		if (id == group->head->id)
		{
			group->head = nullptr;
		}
	}
	
}


void Deanery::assign_head(const string& title, const int& id)
{
	Group* group = find_group(title);
	Student* stud = group->find_id(id);
	group->assign_head(stud);
}


void Deanery::rand_heads()
{
	random_device rd;
	mt19937 mersenne(rd());
	for (Group* gr : groups)
	{
		int rand_student_pos = mersenne() % gr->students.size();
		assign_head(gr->title, gr->students[rand_student_pos]->get_id());
	}
}


void Deanery::remove(const string& title, const int& id)
{
	Group* group = find_group(title);
	Student* stud = group->find_id(id);
	group->expel(stud);
	if (stud->id == group->head->id)
	{
		group->head = nullptr;
	}
	delete stud;
}


void Deanery::output_data(const string& fname) {
	ofstream file(fname);
	for (Group* group : groups)
	{
		file << group->title << " " << group->spec << endl;
		for (size_t i = 1; i < group->students.size(); ++i)
		{
			file << i << ". " << group->students[i]->fio << " id: " << group->students[i]->id << endl;
		}
		file << endl;
	}
}


void Deanery::print_student_info(const string& title, const int& id)
{
	Group* group = find_group(title);
	Student* stud = group->find_id(id);
	cout << "Name: " << stud->fio << "\nGroup: " << stud->group << "Marks: " << endl;
	for (int mark : stud->marks )
	{
		cout << mark << " ";
	}
	cout << endl;
}

int Deanery::total_num_of_stud()
{
	size_t sum = 0;
	for (Group* gr : groups)
	{
		sum += gr->size();
	}
	return sum;
}