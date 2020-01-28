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
    int num = marks.size();
    int sum = 0;
    for (size_t i = 0; i < num; i ++)
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

Student::~Student()
{
}