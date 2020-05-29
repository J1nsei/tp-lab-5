#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

Student::Student()
{
    this->group = nullptr;
}
Student::Student(uint32_t id, string fio)
{
    this->id = id;
    this->fio = fio;
    this->group = nullptr;
}

void Student::setGroup(Group* newGroup)
{
    group = newGroup;
}

double Student::getAverageMark() const
{
    if(marks.empty())
        return 0.0;

    double sum = 0.0;
    for (auto& mark : marks)
    {
        sum += mark;
    }
    return sum / marks.size();
}


uint32_t Student::getId() const
{
    return id;
}
string Student::getFio() const
{
    return fio;
}
Group* Student::getGroup() const
{
    return group;
}
vector<int> Student::getMarks() const
{
    return marks;
}

