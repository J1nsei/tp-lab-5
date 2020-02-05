//
// Created by Илья on 026 26.01.20.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H


#include "group.h"

class Student{
private:
    int id;
    string fio;
    Group * group;
    vector<int> marks;

public:

    int getId();
    string getFio();

    Student(int id, string fio);
    void addToGroup(Group * group);
    void addMark(int mark);
    double calcAverageMark();
    vector<int>& getMarks();
};


#endif //TASK1_STUDENT_H
