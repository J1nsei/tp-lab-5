//
// Created by Оксана on 16.01.2020.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H


#include <vector>
#include <string>
#include <iostream>
#include <Group.h>
#include <Student.h>
using namespace std;


class Group;
class Student;


class Dean {
public:
    Dean();
    ~Dean();
    vector<string> split (const string &, char);
    //void Add_students();//создание студентов на основе данных из файла
    //void Add_groups();//создание групп на основе данных из файла
    void Add_marks(string, int);//добавление случайных оценок студентам
    vector<pair<vector<string>,pair<int,int>>> Get_state(); //получение статистики по успеваемости студентов и групп
    void Check_and_delete_students();//отчисление студентов за неуспеваемость
    void Choose_head(string);//инициация выборов старост в группах
    Group* Search_of_group(string);
    void Print_date();//вывод данных на консоль
    void Transfer_of_student(string, string, string);//перевод студентов из группы в группу
    vector<Student*> Get_students();
    vector<Group*> Get_groups();
    void Update_file(const string filename); //сохранение обновленных данных в файла


private:
    int id = 0;
    vector<pair<string,string> > Names_of_groups;//массив групп
    vector<Student*> students;
    vector<string> Names_of_students;
    vector<Group*> groups;
    void Add_students();
    void Add_groups();




};

#endif //TASK1_DEAN_H
