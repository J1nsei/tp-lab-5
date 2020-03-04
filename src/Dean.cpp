#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Dean.h"

Dean::Dean(std::string name)
{
	this->name = name;
}

Group* Dean::search_group_name(std::string group_name)
{
	for (Group group : groups)
		if (group->title == group_name)
			return group;
	return nullptr;
}
void Dean::add_student_to_group(std::string fio, std::string group_name) {
	id++;
	Student *student = new Student(fio, id);
	for (auto grp : groups)
		if (grp->title == group_name)
			grp->addstudent(*student);
}

void Dean::create_group(std::string group_name, std::string spec)
{
	groups.push_back(new Group(group_name, spec));
}

void Dean::add_mark_to_student(std::string group_name, std::string name, int mark)
{
	Group* grp = search_group_name(group_name);
	Student stud = grp->search_student_name(name);
	stud.add_mark(mark);
	for (int i = 0; i < grp->students.size(); i++)
		if (grp->students[i].getname() == stud.getname())
		{
			grp->students[i] = stud;
			break;
		}

}


Student Dean::move_students(std::string name, std::string group1, std::string group2)
{
	Group* grp1 = search_group_name(group1);
	Group* grp2 = search_group_name(group2);
	Student student = grp1->search_student_name(name);
	grp1->kick_from_group(student);
	grp2->addstudent(student);
	return student;
}

void Dean::kick_student(Student student)
{
	student.group->kick_from_group(student);
}

void Dean::init_head(std::string group_name)
{
	Group* grp = search_group_name(group_name);
	grp->headman();
}
void Dean::update_data(std::string filename)
{
	std::ofstream fout(filename);
	for (auto group : groups)
		for (auto student : group->students)
			fout << student.id << ". " << student.fio << group->title << std::endl;
}

void Dean::print_data()
{
	std::cout << "Name of faculty: " << name << std::endl;
	for (auto group : groups)
	{
		std::cout << group->title << " " << group->spec << std::endl;
		std::cout << "Headman: " << group->head << std::endl;
		std::cout << "Number of students: " << group->students.size() << std::endl;
		std::cout << "Average score of the group: " << group->average_score() << std::endl;
		for (auto student : group->students)
			std::cout << student.id << ". " << student.fio << student.avg_mark() << std::endl;
	}

}
