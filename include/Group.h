//
// Created by Оксана on 16.01.2020.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <vector>
#include <string>
#include "Student.h"

using namespace std;


class Group {
public:
    Group(string, string); //создание группы с указанием названия
    void Add_student(Student*); //добавление студента
    void Election_of_the_head(Student*); //избрание старосты
    Student* Search_of_student(string); //поиск студента по ФИО
    Student* Search_of_student(int);
    double  Calc_aver_mark_in_group(); //вычисление соеднего балла в группе
    void Exclusion_student(int); //исключение студента из группы
    void Exclusion_student(string); //исключение студента из группы
    vector<Student*> Get_students() const;
    string Get_title() const;
    string Get_spec() const;;
    Student* Get_head() const;
    unsigned int Get_size() const;
private:
    string title; // название группы
    string spec; // специальность
    vector<Student*> students;// students - вектор ссылок на студентов
    Student* head; // ссылка на старосту (из членов группы)
};

#endif //TASK1_GROUP_H
