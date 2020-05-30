#ifndef GROUP_H
#define GROUP_H

#include "student.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Group
{
private:
    std::string title;
    vector<Student*> students;
    Student* head{};

public:
    friend class Deanery;

    explicit Group(std::string title);

    void addStudent(Student* student);
    Student* electHeadman();
    Student* searchStudent(int id);
    double getAverageMark();
    void deleteStudent(int id);
    int getGroupSize();
};
#endif