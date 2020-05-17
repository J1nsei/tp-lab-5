#ifndef Student_h
#define Student_h

#include <stdio.h>
#include "Group.h"
#include <string>
#include <vector>

using namespace std;

class Group;
class Student{
private:
    int id;
    string fio;
    Group* group;
    vector<int> marks;
public:
    Student(int id, string fio);
    void addToGroup(Group* group);
    void addMark(int mark);
    float getAverageMark();
    int getID();
    string getFIO();
    Group* getGroup();
    vector<int> getMarks();
};
#endif
