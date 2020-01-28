#include "Group.h"

Group::Group(std::string title, std::string spec)
{
    this -> title = title;
    this -> spec = spec;
}

void Group::addStudent(Student* student)
{
    students.push_back(student);
}

void Group::electionOfHead()
{
    size_t num = rand() % students.size();
    head = students[num];
}

int Group::findByName(std::string name) const
{
    for (long unsigned int i = 0; i < students.size(); i++)
    {
        if (students[i]->getFIO() == name)
        {
            return i;
        }
    }
    return -1;
}

int Group::findByID(unsigned int id) const
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i]->getID() == id)
        {
            return i;
        }
    }
    return -1;
}

void Group::estimate(unsigned int id)
{
    if (this->findByID(id) != -1)
    {
        int mark = rand() % 10;
        students[findByID(id)]->addMark(mark);
    }
} 

int Group::findMean() const
{
    int num = students.size();
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += students[i]->calcMean();
    }
    int res = sum / num;
    return res;
}

void Group::exclude(unsigned int id)
{
    int index = this->findByID(id);
    if (index != -1)
    {
        students.erase(students.begin() + index);
    }
}   

Group::~Group()
{
}
