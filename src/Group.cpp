#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Student.h"
#include "Group.h"
using namespace std;

Student Group::electHead()
{
    random_device rdev{};
    default_random_engine generator{rdev()};
    uniform_int_distribution<int> distribution(0,getSize()-1);
    int dice_roll = distribution(generator);
    Student newHead = students[dice_roll];
    head = newHead;
    return newHead;
}
void Group::addStudent(Student student)
{
    student.setGroup(this);
    this->students.push_back(student);
}
void Group::expelStudent(Student student)
{
    size_t pos = 0;
    for(auto& member : students)
    {
        if(member.getId() == student.getId())
        {
            break;
        }
        pos++;
    }
    vector<Student>::iterator  pos_it = students.begin() + pos;
    students.erase(pos_it);
}
Group::Group(string name, string spec)
{
    this->name = name;
    this->spec = spec;
}

Student* Group::findStudent(uint32_t id)
{
    for(size_t i = 0; i < getSize(); i++)
    {
        if(students[i].getId() == id)
        {
            return &students[i];
        }
    }
    return nullptr;
}
Student* Group::findStudent(string fio)
{
    for(size_t i = 0; i < getSize(); i++)
    {
        if(students[i].getFio() == fio)
        {
            return &students[i];
        }
    }
    return nullptr;
}

double Group::computeAverageMark() const
{
    double sum = 0;
    for(auto& member : students)
    {
        sum+=member.getAverageMark();
    }
    return sum/this->getSize();
}
string Group::getName() const
{
    return name;
}
string Group::getSpec() const
{
    return spec;
}
Student Group::getHead() const
{
    return head;
}
size_t Group::getSize() const
{
    return students.size();
}

void Group::printGroup(ostream& out) const
{
    out << "Group: "<<endl;
    out << this->getName() << ":" << this->getSpec() << endl;
    out << "Number of students:" << this->getSize() << endl;
    out << "Average mark:" << this->computeAverageMark() << endl;
    out << "Head student: " << this->getHead().getId() << ":" << this->getHead().getFio() << endl;

    for(auto& student : this->students)
    {
        out << student.getId() << ":" << student.getFio() << ":" << endl;
        out << "{ ";
        for(auto& mark : student.getMarks())
        {
            out << mark << ", ";
        }
        out << "}"<<endl;
    }
}
