//
// Created by Egor on 22.01.2020.
//
#include <algorithm>
#include "student.h"
#include "group.h"

Student::Student(std::string FIO)
{
    this->FIO = FIO;
    this->ID = Student::static_ID;
    Student::static_ID++;
}

bool Student::AddToGroup(Group* groupToAdd)
{
    if (groupToAdd == nullptr)
    {
        this->group = groupToAdd;
        return true;
    }
    else
    {
        if (std::find(groupToAdd->students.begin(), groupToAdd->students.end(), this) != groupToAdd->students.end())
            return false;

        this->group = groupToAdd;
        groupToAdd->students.push_back(this);

        return true;
    }
}

void Student::AddMark(int mark)
{
    this->marks.push_back(mark);
}

int Student::GetAverageMark()
{
    int sum = 0;
    for (auto mark : this->marks)
        sum += mark;

    if (this->marks.empty())
        return 0;

    return sum / this->marks.size();
}

int Student::GetID()
{
    return this->ID;
}

std::string Student::GetFIO()
{
    return this->FIO;
}
