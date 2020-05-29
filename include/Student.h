#pragma once
#include <string>
#include <vector>
using namespace std;

class Group;

class Student
{
private:
    uint32_t id;
    string fio;
    Group* group;
    vector<int> marks;
public:
    Student();
    Student(uint32_t id, string fio);
    void setGroup(Group* newGroup);
    double getAverageMark() const;

    uint32_t getId() const;
    string getFio() const;
    Group* getGroup() const;
    vector<int> getMarks() const;

    friend class Deanery;
};
