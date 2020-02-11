#ifndef LAB5_GROUP_H
#define LAB5_GROUP_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Group{
private:
    string title;
    string spec;
    vector<Student*> students;
    Student* head;

public:
    explicit Group(string);

    string GetTitle();
    int GetAverageGroupMark();
    string GetHead();

    bool AddStudent(Student* );
    void AddHead();
    bool FindStudent(int);
    bool DeleteStudent(Student*);

    friend bool Student::AddGroup(Group *);
    friend class Deanery;
};
#endif //LAB5_GROUP_H
