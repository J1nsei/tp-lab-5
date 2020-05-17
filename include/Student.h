#ifndef Student_h
#define Student_h

#include <stdio.h>
#include "Group.h"
#include <string>
#include <vector>

class Group;
class Student{
private:
    int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
public:
    Student(int id, std::string fio);
    void addToGroup(Group* group);
    void addMark(int mark);
    float getAverageMark();
    int getID();
    std::string getFIO();
    Group* getGroup();
    std::vector<int> getMarks();
};
#endif
