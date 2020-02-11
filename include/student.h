#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H
#include <iostream>
#include "string.h"
#include <vector>
using namespace std;

static int generatorId = 0;
class Group;

class Student{
private:
    string fio;
    int id;
    Group *group;
    vector<int> marks;

public:
    explicit Student(string studentFio);

    string GetFio();
    int GetID();
    int GetAverageMark();
    bool AddGroup(Group*);
    void AddMark(int);

    friend class Deanery;
};
#endif //LAB5_STUDENT_H
