//
// Created by Anton Korkunov on 16/01/2020.
//

#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H
#include <cstdio>
#include <vector>
#include <string>
//#include "Group.h"

using namespace std;

//class Group{};
class Group;
class Deanery;

class Student{
private:
    int id;
    string name;
    Group * group;
    vector<int> marks;
public:
    Student();
    void create(string _name,int nowid);
    void ingroup(Group * _group);
    void addmark();
    double countAve();
    string getName();
    Group * getGroup();
    int getMarkssize();
};
#endif //LAB5_STUDENT_H
