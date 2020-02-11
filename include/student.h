//
// Created by Mary on 22.01.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "group.h"

using namespace std;
class Group;

class Student{
private:
    int id;
    string fio;
    Group *group;
    vector<int> marks;
public:
    int getNumberOfMarks();
    Student(int id, string fio);
    int getId();
    string getFio();
    void setGroup(Group* group);
    void addMark(int mark);
    double getAverageMark();
};


#endif //TASK1_STUDENT_H
