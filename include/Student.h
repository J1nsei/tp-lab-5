//
// Created by Оксана on 15.01.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H
#include <vector>
#include <string>
using namespace std;

class Group;

class Student {
public:
    Student();
    Student(unsigned int, string);
    void Add_mark(unsigned int);
    double Calc_aver_mark();
    void Set_mark(unsigned int);
    void Set_group(Group*);
    string Get_fio() const;
    int Get_id() const;
    Group* Get_Group() const;
    vector<unsigned int> Get_marks() const;


private:
    int id; //идентификационный номер
    string fio; // фамилия и инициалы
    Group* group; //ссылка на группу (объект Group)
    vector<unsigned int> marks; //  вектор оценок
};



#endif //TASK1_STUDENT_H
