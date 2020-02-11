//
//  Classes.hpp
//  lab5
//
//  Created by Андрей Журавлев on 28.01.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Classes_hpp
#define Classes_hpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

#define NUMBERS_SET "0123456789"

class Group;

//MARK: Studen Class
class Student {
private:
    std::string last_name, first_name, second_name;
    std::vector<int> marks;
	float mean_mark;
    Group *group;
    size_t num;
    id_t id;
    bool is_head;
public:
    Student(std::string id_and_fio, Group* group);
    ~Student();
    
	void group_enroll(Group* group) {this->group = group;}
    void add_mark(unsigned int mark);
    float mean_marks();
	float get_mean() {return mean_mark;}
	id_t get_id() {return id;}
	std::string get_last_name() {return last_name;}
	std::string get_first_name() {return first_name;}
	std::string get_secong_name() {return second_name;}
	void set_as_head() {is_head = true;}
    void print_st_data_short();
    void print_fio();
	bool is_group_head() {return is_head;}
};

//MARK: Group Class
class Group {
private:
    std::string title;
    std::string spec;
    size_t quantity;
    Student *head;
    std::vector<Student*> students;
	float group_mean;
    
    bool _check_fio(std::vector<std::string> arr1, std::vector<std::string> arr2);
	void _add_student_to_arr(Student* st, size_t pos);
	void _del_student(std::vector<Student*>::iterator iter, bool delete_student = true);
public:
    Group(std::string title);
	
	static std::vector<std::string> split(std::string str, std::string sep);
    
    bool create_student(std::string str);
	bool add_student(Student* student);
    Student* head_choice();
    float mean_mark_group();
    void add_marks();
    bool transfer_to_group(id_t id, Group* group);
    bool is_student_exist(id_t id);
    bool expell_student(size_t index);
	bool expell_by_id(id_t id);
    std::vector<id_t> choose_students_to_expell();
    Student* search_student(id_t id);
    Student* search_student(std::string fio);
    void print_group_data();
	std::vector<Student*> get_students() {return students;}
	float get_group_mean() {return group_mean;}
};

//MARK: Deanery Class
class Deanery {
private:
    std::map<std::string, Group*> groups;
    
public:
    Deanery(std::string stud_file_name, std::string gr_file_name);
    void add_marks_for_groups();
    bool student_transfer(id_t id, std::string from_group, std::string to_group);
    bool expell_one_student(id_t id);
    void expell_students();
    void head_choices();
	void head_choices_in_group(std::string group_name);
    void data_output();
    void save_data(std::string file_name);
	void calculate_means();
};

#endif /* Classes_hpp */
