#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Group;
class Deanery;

// STUDENT

class Student {
	friend Group;
	friend Deanery;
private:
	int id; // »дентификатор студента
	std::string fio; // фамили€ 
	Group* group; // ссылка на группу
	std::vector<int> marks; // вектор оценок
	int num_marks;//сколько оценок
	double avg_mark;// средн€€ оценка

public:
	Student(int , std::string );// конструктор 
	void addGroup(Group* ); // добавление в группу 
	void addMark(int);// добавление в вектор оценок новой оценки 
	double cnt_aver_marks(); // вычисление средней оценки студента
	
};

//GROUP

class Group {
	friend Deanery;
private:
	std::string title; // название группы
	std::vector <Student*> students;// вектор студентов
	Student* head;// староста
	int num_sd_in_group; // количество студентов 

public:
	Group(std::string );
	void addStudent(Student* );
	void electHead();
	void search_stud(int );
	double avg_group_mark();
	void del_stud(int);
	
};

//DEANERY

class Deanery {
private:
	std::string fileStud;
	std::string fileGroup;
	std::vector<Group*> groups;	// вектор групп
	std::vector<Student*> students;	// вектор всех студентов
	int num_stud_ovall, num_group; // количество студентов, групп
	

public:
	Deanery(std::string, std::string);
	void create_students();
	void create_groups();
	void add_marks();
	void do_stat();
	void choose_heads();
	void move_student(std::string, std::string);
	void kick_stud();
	void print();
};