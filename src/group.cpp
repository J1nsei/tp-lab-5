//
// Created by Egor on 22.01.2020.
//
#include <algorithm>
#include "student.h"
#include "group.h"

Group::Group(std::string title)
{
    this->title = title;
}

bool Group::AddStudent(Student* student)
{
    if (std::find(this->students.begin(), this->students.end(), student) != this->students.end())
        return false;

    this->students.push_back(student);
    student->AddToGroup(this);

    return true;
}

bool Group::FindStudent(int ID)
{
    for (auto student : this->students)
        if (student->GetID() == ID)
            return true;

    return false;
}

bool Group::FindStudent(std::string FIO)
{
    for (auto student : this->students)
        if (student->GetFIO() == FIO)
            return true;

    return false;
}

int Group::GetAverageGroupMark()
{
    int sum = 0;
    for (auto student : this->students)
        sum += student->GetAverageMark();

    return sum / this->students.size();
}

bool Group::KickStudent(Student* student)
{
    if (!this->FindStudent(student->GetID()))
        return false;

    student->AddToGroup(nullptr);

    int index = 0;
    for (auto elem : this->students)
    {
        if (elem == student)
            break;
        index++;
    }

    this->students.erase(this->students.begin() + index);
}

std::string Group::GetTitle()
{
    return this->title;
}

void Group::SetHead()
{
    int max = 0;
    Student* currentHead = nullptr;

    for (auto student : this->students)
    {
        if (student->GetAverageMark() >= max)
        {
            currentHead = student;
            max = student->GetAverageMark();
        }
    }

    this->head = currentHead;
}

std::string Group::GetHead()
{
    return this->head->GetFIO();
}


