#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include <vector>

#include "Group.h"

using namespace std;

class Student {
private:
    int id;
    string fio;
    Group* g;
    vector<int> marks;

public:
    Student(int id, string fio);
    ~Student();

    void setGroup(Group* g);
    void setMarks(vector<int> &marks);
    double averageMark();
    int getId();
    string getFio();
    void addMark(int mark);

};


#endif //UNTITLED_STUDENT_H
