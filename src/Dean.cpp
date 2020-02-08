#include "Dean.h"


using namespace std;

Dean::Dean(Group group) {
	add_group(group);
}

Dean::Dean(const string& filename) {
	perform_file(filename);
}

void Dean::add_group(const Group& group) {
	groups.push_back(group);
}

void Dean::check_students()
{
	for (auto& group : groups) {
		int size = group.get_size();
		int i = 0;
		while (i < size) {
			if (group.search_Student(i)->average_Mark() < 3.5) {
				cout << "Студент " << group.search_Student(i)->get_name() << " имеет плохую успеваемость, его средний балл равен: " << group.search_Student(i)->average_Mark() << "\n";
				i++;
			}
			else {
				i++;
			}
		}
	}
}



void Dean::check_delete_students()
{
	for (auto& group : groups) {
		int size = group.get_size();
		int i = 0;
		while (i < size) {
			if (group.search_Student(i)->average_Mark() < 3.5) {
				cout << "Студент " << group.search_Student(i)->get_name() << " был исключен за неуспеваемость из группы " << group.get_title() << " Потому что его средний балл равен " << group.search_Student(i)->average_Mark() << "\n";
				group.Delete_students(i);
				size--;
				i++;
			}
			else {
				i++;
			}
		}
	}
}

void Dean::add_random_marks(string group_name, int count)
{
	for (auto& group : groups) {
		if (group.get_title() == group_name) {
			for(size_t k = 0; k < group.get_size();k++){
				for (int i = 0; i < count; i++) {
					int mark = rand() % 10;
					group.search_Student(k)->add_Mark(mark);
				}
			}
		}
	}
}

vector<string> Dean::split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}



void Dean::create_students()
{
	ifstream file("student.txt");
	//system("chcp 65001");
	while (!file.eof()) {
		string buf;
		getline(file, buf, '\n');
		vector<string> data = split(buf, ':');
		for (auto s : data)
			cout << s << " ";
		for (auto group : groups) { 
			if (group.get_title() == data[1]) {
				group.add_Student(data[0]);
			}
			else {
				Group group1(data[1]);
				groups.push_back(group1);
			}
		}
	}     
}

void Dean::transfer_student(string name, string name_from, string name_to)
{
	Group* group_from = find_group(name_from);
	Group* group_to = find_group(name_to);
	Student* student_ptr = group_from->search_Student(name);
	if (student_ptr != nullptr && group_from != nullptr && group_to != nullptr) {
		Student student_copy = *student_ptr;
		group_from->Delete_students(name);
		group_to->add_Student(name);
		vector<int> marks = student_copy.get_marks();
		set_marks(name_to, group_to->get_size() - 1, marks);
		cout<<"Студент "<< student_copy.get_name()<<" был переведен из группы "<< group_from->get_title()<< " в группу "<<group_to->get_title()<<"\n";
	}
	else {
		cout << "Вы ввели некорректные данные! \n" << endl;
	}
}

void Dean::set_marks(const string name_from, int id, const vector<int> marks)
{
	Group* group = find_group(name_from);
	Student* name = group->search_Student(id);
	for (auto& mark : marks) {
		name->add_Mark(mark);
	}
}

void Dean::choose_head(const string group_name)
{  
	Group* ptr = find_group(group_name);
	if (ptr != nullptr) {
		ptr->add_head(rand() % ptr->get_size());
	}
	else {
		cout << "Нет такой группы! Староста не моет быть выбран" << endl;
	}
}

Group* Dean::find_group(const std::string& group_name) {
	for (auto& group : groups) {
		if (group.get_title() == group_name)
			return &group;
	}
	return nullptr;
}

void Dean::perform_file(const string& filename) {
	ifstream file(filename);
	//system("chcp 1251");
	if (file.is_open()) {
		while (!file.eof()) {
			string buf;
			getline(file, buf, '\n');
			vector<string> data = split(buf, '_');
			Group* group = find_group(data[1]);
			if (group == nullptr) {
				Group tmp(data[1]);
				add_group(tmp);
				find_group(data[1])->add_Student(data[0]);
			}
			else {
				group->add_Student(data[0]);
			}
		}
		file.close();
	}
}

void Dean::data_output(const string filename)
{
	ofstream file(filename);
	if (file.is_open()) {
		for (auto group : groups)
		{
			file << "Название группы: " << group.get_title() << endl;
			file << "Количество студентов: " << group.get_size() << endl;
			file << "Староста группы: " << group.get_head().get_name() << endl;
			for (size_t j = 0; j < group.get_size(); j++) {
				Student* student = group.search_Student(j);
				file << "Средняя оценка студента: " << student->get_name() << " - " << student->average_Mark() << " \n";
				file << "Все оценки студента: {";
				for (auto& mark : student->get_marks()) {
					file << " " << mark;
				}
				file << "}  \n" << endl;
			}
		}
	}
}
vector<Group> Dean::get_groups() const { return groups; }





