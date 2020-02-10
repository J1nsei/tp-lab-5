#include "Header.h"
//STUDENT
Student::Student(int tmp_ID, std::string tmp_FIO) { // инициализация
	id = tmp_ID;
	fio = tmp_FIO;
	avg_mark = 0;
}

void Student::addGroup(Group* tmp_GROUP) { // добавление поля группы
	this->group = tmp_GROUP;
}

void Student::addMark(int tmp_MARK) { // добавление оценки
	marks.push_back(tmp_MARK);
	num_marks = marks.size();
}

double Student::cnt_aver_marks() { //вычисление средней оценки
	double sum = 0;
	for (int i = 0; i < num_marks;i++)
		sum += marks[i];
	avg_mark = sum / num_marks;
	return sum / num_marks;
}

// GROUP
Group::Group(std::string tmp_TITLE) {
	title = tmp_TITLE; // инициализация
}

void Group::addStudent(Student* tmp_STUDENT) { // вектор студентов в группе
	students.push_back(tmp_STUDENT);
	num_sd_in_group = students.size();
}
void Group::electHead() { // избрание старосты
	head = students[rand() % num_sd_in_group];
	
}
bool Group::search_stud(int tmp_ID) {
	bool found = 0;
	for (int i = 0; i < num_sd_in_group; i++) {
		if (students[i]->id == i) {
			std::cout << "Студент "<< students[i]->fio << " найден"<< "\n";
			found = 1;
		}
	}
	if (found == 0) {
		std::cout << "Студент не найден" << "\n";
	}
	return found;
}	
double Group::avg_group_mark() {
	double sum = 0;
	for (int i = 0; i < num_sd_in_group; i++) {
		sum += students[i]->avg_mark;
	}
	
	return sum / num_sd_in_group;

}
void Group::del_stud(int tmp_ID) {
	for (int i = 0; i < num_sd_in_group; i++) {
		if (students[i]->id == tmp_ID) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				num_sd_in_group--;
				electHead();
			}
			else {
				students.erase(students.begin() + i);
				num_sd_in_group--;
			}
		}
	}
}

//DEANERY
Deanery::Deanery(std::string students, std::string groups) { // инициализация
	fileGroup = groups; 
	fileStud = students;
}


void Deanery::create_students() {
	std::ifstream file(fileStud);
	std::string fio;
	int id = 0;
	while (std::getline(file, fio)) {
		id++;
		students.push_back(new Student(id, fio));
	}
	file.close();
	num_stud_ovall = students.size();
}


void Deanery::create_groups() {
	std::ifstream file(fileGroup);
	std::string title;
	while (std::getline(file, title)) {
		groups.push_back(new Group(title));
	}
	file.close();
	num_group = groups.size();
	int n = num_stud_ovall / num_group;
	for (int i = 0; i < num_group; i++) {
		for (int j = i * n; j < (i + 1) * n; j++) {
			students[j]->addGroup(groups[i]);
			groups[i]->addStudent(students[j]);
		}
		if (n * num_group < num_stud_ovall) {
			for (int j = n * num_group; j < num_stud_ovall; j++) {
				students[j]->addGroup(groups[i]);
				groups[i]->addStudent(students[j]);

			}
		}
		
	}
}

void Deanery::add_marks() {
	for (int i = 0; i < num_stud_ovall; i++) {
		for (int j = 0; j < 10; j++) {
			students[i]->addMark(rand() %10 + 1);
		}
	}
	for (int i = 0; i < num_stud_ovall; i++) {
		students[i]->cnt_aver_marks();
	
	}
}
void Deanery::choose_heads() {
	for (int i = 0; i < num_group; i++) {
		groups[i]->electHead();
	}
}

void Deanery::do_stat() {

	std::ofstream file;
	file.open("statistics.txt");
	file << "Рейтинг" << std::endl;
	file << "Количество студентов: " << num_stud_ovall << std::endl;
	if (file.is_open()) {
		for (int j = 1; j <= 10; j++) {
			for (int i = 0; i < num_stud_ovall; i++) {
				if (students[i]->cnt_aver_marks() == 11-j) {
					file << students[i]->fio << " - " << students[i]->avg_mark << std::endl;
				}
			}
		}
		for (int i = 0; i < num_group; i++) {
			file << groups[i]->title << " - " << groups[i]->avg_group_mark() << std::endl;
		}
	}
	file.close();
}

void Deanery::move_student(std::string tmp_FIO, std::string new_GROUP) {
	for (int i = 0; i < num_stud_ovall; i++) {
		if (students[i]->fio == tmp_FIO) {
			for (int j = 0; j < num_group; j++) {
				if (groups[j]->title == new_GROUP) {
					students[i]->group->del_stud(students[i]->id);
					students[i]->addGroup(groups[j]);
					groups[j]->addStudent(students[i]);
					break;
				}
			}
		}
	}
}


void Deanery::kick_stud() {
	for (int i = 0; i < num_stud_ovall; i++) {
		if (students[i]->cnt_aver_marks() <= 3) {
			students[i]->group->del_stud(students[i]->id);
			students.erase(students.begin() + i);
			num_stud_ovall--;
		}
	}
}


void Deanery::print() {
	std::cout << "Общее количество студентов: " << num_stud_ovall << std::endl;
	for (int i = 0; i < num_group; i++) {
		std::cout << "В группе: " << groups[i]->title <<std::endl;
		std::cout << "Колличество студентов: " << groups[i]->num_sd_in_group << std::endl;
		std::cout << "Староста: " << groups[i]-> head-> fio  << std::endl;
		std::cout << std::endl;
		for (int j = 0; j < groups[i]->num_sd_in_group; j++) {
			std::cout <<" ID: "<< groups[i]->students[j]->id << " "<< groups[i]->students[j]->fio << ", средняя оценка: " << groups[i]->students[j]-> avg_mark << std::endl;
			
		}
		std::cout << std::endl;
	}
}
