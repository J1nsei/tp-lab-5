#include "group.h"
#include "student.h"
#include <utility>

Student::Student(int id, std::string fio)
{
    this->fio = std::move(fio);
    this->id = id;
}

unsigned int Student::getID()
{
    return id;
}

std::string Student::getFIO()
{
    return fio;
}

void Student::addToGroup(std::string target_group)
{
    this->group = std::move(target_group);
}

void Student::setMarks(int mark)
{
    this->marks.push_back(mark);
}

vector<int>& Student::getMarks()
{
    return marks;
}

unsigned long Student::getAverageMarks()
{
    unsigned long marksSum = 0;
    for (int mark : marks)
    {
        marksSum += mark;
    }
    return marksSum / marks.size();
}