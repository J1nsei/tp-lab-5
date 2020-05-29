//
// Created by Mikhail on 22.01.2020.
//

#ifndef TASK1_STUDENT_H
#define TASK1_STUDENT_H

#include <iostream>
#include <vector>

typedef unsigned int mark_t;

using std::string;
using std::vector;

class Group;

class Student{
private:
    int ID;
    string FIO;
    Group* group{nullptr};
    vector<mark_t> marks;
public:
    Student(int ID, string FIO);
    void setGroup(Group* group);
    void addMark(mark_t mark);
    Group* getGroup();
    const string& getFIO() const;
    int getID() const;
    mark_t getMean() const;
    vector<mark_t> getMarks() const;
};

#endif //TASK1_STUDENT_H
