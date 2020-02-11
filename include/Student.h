//
// Created by aklen on 28.01.2020.
//
#include <iostream>
#include "string.h"
#include <vector>
using namespace std;


class Group;

static int new_id = 0;

class Student{
private:
    int id;
    string fio;
    Group *group;
    vector<int> marks;

public:
    explicit Student(string);
    bool joinToGroup(Group*);
    void addMark(int);
    int getAverageMark();
    int getID();
    string getFio();

    friend class Deanery;
};