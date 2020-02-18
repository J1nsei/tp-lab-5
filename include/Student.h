#pragma once
#include <string>
#include <vector>
#include "Group.h"

class Student {

private:
    int id;
    class Group* group;
    std::string fio;
    std::vector<int> marks;

public:
    Student(std::string fio, Group* group, int id);
    ~Student();

    int getId();
    Group* getGroup();
    void setGroup(Group* actualGroup);
    std::string getFio();
    std::vector<int> getMarks();
    double getAverageMark();
    void addMark(int mark);
};