//
// Created by Egor on 22.01.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H

#include <string>
#include <vector>

class Group;

class Student
{
public:
    static int static_ID;

    explicit Student(std::string);
    bool AddToGroup(Group*);
    void AddMark(int);
    int GetAverageMark();
    int GetID();
    std::string GetFIO();

    friend class Dean;
private:
    int ID;
    std::string FIO;
    Group* group;
    std::vector<int> marks;
};

#endif //TASK1_STUDENT_H
