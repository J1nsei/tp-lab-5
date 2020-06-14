#include "group.h"
#include "student.h"
#include "dean.h"

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string>tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

Dean::Dean()
{

}

void Dean::create_group(std::string fname)
{
	std::ifstream file(fname);
	system("chcp 65001");
	while (!file.eof())
	{

		std::string buf;
		getline(file, buf, '\n');
		std::vector<std::string> data = split(buf, ':');
		Group* g = new Group(data[1]);
		g->spec = data[0];
		this->groups.push_back(g);
		std::cout << std::endl;
	}
}

void Dean::create_student(std::string fname)
{
	std::ifstream file(fname);
	system("chcp 65001");
	while (!file.eof())
	{
		std::string buf;
		getline(file, buf, '\n');
		std::vector<std::string> data = split(buf, ':');
		int id = 0;
		for (int i = 0; i < data[0].length(); i++)
		{
			id = id * 10 + data[0][i] - 0x30;
		}
		Student* s = new Student(id, data[1]);
		Group* g;
		for (auto i : this->groups)
		{
			if (i->name == data[2])
			{
				g = i;
				s->add_group(g);
			}
		}
		this->students.push_back(s);
	}
}

void Dean::add_marks(int n)
{

	for (int i = 0; i < this->students.size(); i++)
	{
		int knowldge = 3 + rand() % 3;
		while (this->students[i]->marks.size() < n)
		{
			int m = 1 + rand() % 5;
			if ((knowldge - 1 <= m) && (m <= knowldge))
			{
				this->students[i]->marks.push_back(m);
			}
		}
	}
}

void Dean::check_info()
{
	for (auto i : this->groups)
	{
		std::cout << i->spec << " " << i->name << ", average: " << i->average() << std::endl;
		for (auto j : i->students)
		{
			std::cout << "\t" << j->id << " " << j->fio << ", average: " << j->average() << std::endl;
		}
	}
}

void Dean::moving(Student* s, Group* to)
{
	Group* g = s->group;
	int id = s->id;
	s->add_group(to);
	g->exclude(id);
}

void Dean::expuls()
{
	for (auto i : this->students)
	{
		if (i->average() < 3.0)
		{
			Group* g = i->group;
			int id = i->id;
			g->exclude(id);
		}
	}
}

void Dean::chose_head()
{
	for (auto i : this->groups)
	{
		i->set_head();
	}
}

void Dean::to_file()
{
	std::ofstream fout;
	fout.open("info.txt");

	for (auto i : this->groups)
	{
		fout << i->spec << " " << i->name << ", average: " << i->average() << std::endl;
		for (auto j : i->students)
		{
			fout << "\t" << j->id << " " << j->fio << ", average: " << j->average() << std::endl;
		}
	}
	fout.close();
}

Student* Dean::get_S(int n)
{
	if (n < this->students.size())
	{
		return this->students[n];
	}
}
Group* Dean::get_G(int n)
{
	if (n < this->groups.size())
	{
		return this->groups[n];
	}
}