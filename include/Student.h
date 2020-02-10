//
// Created by Илья Соловьёв on 15.01.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H

#include <string>
#include <vector>
#include "Deanery.h"


class Group;

class Deanery;

class Student {

    friend Group;
    friend Deanery;

    int id;
    std::string fio;
    Group *group;
    std::vector<int> marks;

    void addMark(int mark);

    void enrollInGroup(std::string title, Deanery *deanery);

public:

    Student(int id, std::string fio);

    double calculateAveregeMark();
};

#endif //TASK1_STUDENT_H
