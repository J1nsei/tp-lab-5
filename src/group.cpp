#include "dean.h"
#include "group.h"
#include "student.h"
#include <utility>

Group::Group(std::string title)
{
    this->title = std::move(title);
}

void Group::addStudent(Student *student)
{
    this->students.push_back(student);
}

Student* Group::electHeadman()
{
    if (!students.empty())
    {
        if (students.size() > 1)
        {
            int headman = rand() % students.size();
            head = students[headman];
            return head;
        }
        else head = students[0];
        return head;
    }
    else return nullptr;
}

Student* Group::searchStudent(int id)
{
    for (auto & student : this->students)
    {
        if (student->getID() == id)
            return student;
    }
    return nullptr;
}

double Group::getAverageMark()
{
    double sum = 0;
    for (auto & student : students)
    {
        sum += student->getAverageMarks();
    }
    return sum / students.size();
}

void Group::deleteStudent(int id)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->id == id)
        {
            if (students[i] == head)
            {
                students.erase(students.begin() + i);
                electHeadman();
            }
            else
            {
                students.erase(students.begin() + i);
            }

        }
    }
}

int Group::getGroupSize()
{
    return students.size();
}