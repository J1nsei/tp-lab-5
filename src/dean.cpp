#include "dean.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "student.h"
#include "group.h"

using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> words;
	string word;
	istringstream wordStream(s);
	while (getline(wordStream, word, delimiter))
		words.push_back(word);
	return words;
}

Dean::Dean()
{
	dean_id = 0;
	vector<Group*> groups;
}

void Dean::addGroups(string names_input, string groups_input)
{
	ifstream file;
	file.open(groups_input, ios::in);
	system("chcp 65001");

	string buf;
	vector <string> current_str;
	while (getline(file, buf))
	{
		current_str = split(buf, ':');
		groups.push_back(new Group(current_str[0], current_str[1]));
	}
	file.close();

	file.open(names_input, ios::in);
	
	while (getline(file, buf))
	{
		current_str = split(buf, ':');
		Student* student = new Student(current_str[0], dean_id);

		bool is_constructed = 0;
		int group_num = -1;
		for (unsigned int i = 0; i < groups.size(); i++)
		{
			if (groups[i]->getTitle() == current_str[1])
			{
				is_constructed = 1;
				group_num = i;
			}
		}
		if (!is_constructed)
		{
			Group* group = new Group(current_str[1], "");
			groups.push_back(group);
			group_num = groups.size() - 1;
		}
		groups[group_num]->addStudent(student);
		student->setGroup(groups[group_num]);
		dean_id++;
	}
	file.close();
}

void Dean::set_random_marks(unsigned int number)
{
	for (Group* group : this->groups)
	{
		for (Student* student : group->getStudents())
		{
			for (unsigned int i = 0; i < number; i++)
			{
				student->addMark(rand() % 10 + 1);
			}
		}
	}
}

void Dean::getStatistics() const
{
	for (Group* group : groups)
	{
		group->AverageMarkofGroup();
		vector<Student*> students = group->getStudents();
		//cout << "Excellents in this group:" << endl;
		unsigned int best_mark = 0;
		unsigned int index;
		for (unsigned int i = 0; i < students.size(); i++)
		{
			if ((students[i]->AverageMark()) > best_mark) 
			{
				index = i;
			}
		}
		cout << "Best student : " << students[index]->getName() << endl;
	}	
}

void Dean::changeGroup(string name, string oldGroup, string newGroup)
{
	Group* group1 = nullptr;
	Group* group2 = nullptr;
	for (Group* group : groups)
	{
		if (group->getTitle() == oldGroup)
			 group1 = group;
		if (group->getTitle() == newGroup)
			group2 = group;
	}
	Student* student = group1->findbyName(name);
	
	if ((group1 == nullptr) || (group2 == nullptr))
	{
		cout << "Error. Try again" << endl;
		return;
	}
	else
	{
		group1->expelStudent(student);
		group2->addStudent(student);
	}
}

void Dean::expelStudents()
{
	for(Group* group : groups)
	{
		for (Student* student : group->getStudents())
		{
			if (student->AverageMark() < 4)
			{
				group->expelStudent(student);
			}
		}
	}
}

void Dean::rewriteData(string names_output, string groups_output) const
{
	ofstream file;
	file.open(names_output, ios::out);
	if (file.is_open())
	{
		for (Group* group : groups)
		{
			for (Student* student : group->getStudents())
			{
				cout << student->getName() << " : " << group->getTitle() << endl;
			}
		}
	}
	else
		cout << "File can't be opened" << endl;
	file.close();

	file.open(groups_output, ios::out);
	if (file.is_open())
	{
		for (Group* group : groups)
		{
			cout << group->getTitle() << " : " << group->getSpec() << endl;
		}
	}
	else
		cout << "File can't be opened" << endl;
	file.close();
}

void Dean::chooseHeads()
{
	for (Group* group : groups)
	{
		group->chooseHead();
	}
}