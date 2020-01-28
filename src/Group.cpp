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

size_t Group::findByName(std::string name) const
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i]->getFIO = name)
        {
            return i;
        }
    }
    return NULL;
}

size_t Group::findByID(unsigned int id) const
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i]->getID = id)
        {
            return i;
        }
    }
    return NULL;
}

void Group::estimate(unsigned int id)
{
    if (this->findByID(id) != NULL)
    {
        int mark = rand() % 10;
        students[findByID(id)]->addMark(mark);
    }
} 

int Group::findMean() const
{
    int num = students.size();
    int sum = 0;
    for (size_t i = 0; i < num; i++)
    {
        sum += students[i]->calcMean();
    }
    int res = sum / num;
    return res;
}

void Group::exclude(unsigned int id)
{
    int index = this->findByID(id);
    if (index != NULL)
    {
        students.erase(students.begin() + index);
    }
}   

Group::~Group()
{
}
