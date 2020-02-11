//
// Created by fiskirton on 10.02.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
#include "helper.h"

using namespace std;

class Group;

class Student {

private:

    int id;
    string fio;
    Group * group{};
    vector<int> marks;
    double mean_mark{0.0};

private:

    Student(int id, string fio);

    ~Student();

private:

    void addMark(int mark);

    void setMeanMark();

    void setGroup(Group *);

public:

    int getId() const;

    double getMeanMark();

    const string &getFio() const;

    Group &getGroup();

    const vector<int> &getMarks();

    friend class Group;

    friend class Deanery;

};

#endif //TASK1_STUDENT_H