//
// Created by Anton Korkunov on 16/01/2020.
//

#ifndef LAB5_GROUP_H
#define LAB5_GROUP_H

#include <stdio.h>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class Group{
private:
    string name;
    string spec;
    vector<Student*> students;
    Student* head;
public:
    Group();
    void create(string _title,string _spec);
    void addstud(Student* pupil);
    void chHead();
    bool findS(string _name);
    double cntBall();
    void delStud(int i);
    void giveMarks();
    void drop(double aver);
    string getName();
    string WriteStudents();
};


#endif //LAB5_GROUP_H
