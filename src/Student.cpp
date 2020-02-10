#include "Student.h"

Student::Student(int ID, std::string full_name)
{
    id = ID;
    fio = full_name;
}

void Student::enroll(Group* group) 
{
    this -> group = group;
}

void Student::addMark(int mark) 
{
    marks.push_back(mark);
}

int Student::calcMean() const 
{
    long unsigned int num = marks.size();
    long unsigned int sum = 0;
    for (long unsigned int i = 0; i < num; i ++)
    {
        sum += marks[i];
    }
    int res = sum/num;
    return res;  
}

std::string Student::getFIO() const
{
    return fio;
}

unsigned int Student::getID() const
{
    return id;
}

Group* Student::getGroup() const
{
    return this->group;
}

Student::~Student()
{
}