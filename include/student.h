#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Student
{
private:
    unsigned int id;
    string fio;
    string group;
    vector<int> marks;

public:
    friend class Group;
    friend class Deanery;

    Student(int id, string fio);

    unsigned int getID();
    string getFIO();
    void addToGroup(string group);
    void setMarks(int mark);
    vector<int>& getMarks();
    unsigned long getAverageMarks();
};
#endif