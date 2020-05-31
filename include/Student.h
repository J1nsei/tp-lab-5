#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H
#include <string>
#include <vector>
#include "Group.h"


class Student {
private:
    int id;
    std::string fio;
    class Group* group;
    std::vector<int> marks;

public:
    Student(int id, std::string fio, Group* group1);
    ~Student();

    int getId();
    std::string getFio();
    Group* getGroup();
    std::vector<int> getMarks();

    void addMark(int mark);
    void setGroup(Group* newGroup);
    double getAverageMark();
};


#endif