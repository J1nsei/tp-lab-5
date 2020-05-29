#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "Deanery.h"
using namespace std;

Deanery::Deanery(const string name)
{
    this->name = name;
}
void Deanery::addGroup(const Group& newGroup)
{
    groups.push_back(newGroup);
}
void Deanery::inputData(const string& fileName)
{
    string buf;
    ifstream in(fileName);
    if (in.is_open())
    {
        uint32_t curId = 0;
        while(!in.eof())
        {
            curId++;
            getline(in,buf,':');

            Student newStudent(curId, buf);

            getline(in, buf, '\n');
            Group* curGroup = findGroup(buf);
            if(curGroup)
            {
                newStudent.setGroup(curGroup);
                curGroup->addStudent(newStudent);
            }
            else
            {
                string spec;
                for(size_t i =2; i<buf.size(); i++)
                {
                    if(buf[i] >= 'A' && buf[i] <= 'Z')
                        spec += buf[i];
                }
                Group newGroup(buf, spec);
                this->addGroup(newGroup);
                newStudent.setGroup(&groups[groups.size()-1]);
                groups[groups.size()-1].addStudent(newStudent);
            }
        }
    }
    else
    {
        cout << "File is undefined";
    }
    in.close();
    this->electHeads();
}
Group* Deanery::findGroup(const string& groupName)
{
    for(size_t i = 0; i < getNumberOfGroups(); i++)
    {
        if(groups[i].getName() == groupName)
        {
            return &groups[i];
        }
    }
    return nullptr;
}
void Deanery::addMarks(const string& groupName, size_t number)
{
    Group* bufGroup = findGroup(groupName);
    if(!bufGroup)
    {
        cout << "No such group";
        return;
    }
    random_device rdev{};
    default_random_engine generator{rdev()};
    uniform_int_distribution<int> distribution(0,10);

    for(auto& student : bufGroup->students)
    {
        for( int i = 0; i<number; i++)
        {
            int dice_roll = distribution(generator);
            student.marks.push_back(dice_roll);
        }
    }
}
ostream& Deanery::getStudentStatistic(ostream& out, const string& studentId, const string& groupName)
{
    Group* group_ptr = findGroup(groupName);
    if(!group_ptr)
    {
        return out << "No such group!";
    }
    Student* student_ptr = group_ptr->findStudent(studentId);
    if(!student_ptr)
    {
        return out << "No such student!";
    }
    size_t unsatisfactoryMarks = 0;
    double boundary = 4;
    for(auto& mark : student_ptr->getMarks())
    {
        if(mark < boundary)
        {
            unsatisfactoryMarks++;
        }
    }
    return out << "Student " << student_ptr->getFio() << " have " << unsatisfactoryMarks << " unsatisfactory marks";
}
ostream& Deanery::getGroupStatistic(ostream& out, const string& groupName)
{

    Group* group_ptr = findGroup(groupName);
    if(!group_ptr)
    {
        return out << "No such group!";
    }
    double boundary = 4;
    size_t failureStudents = 0;
    for(auto& student : group_ptr->students)
    {
        double averageMark = student.getAverageMark();
        if(averageMark < boundary)
        {
            failureStudents++;
        }
    }
    return out << "Group " << groupName << " has " << failureStudents << " out of " << group_ptr->getSize() << " failure students"<<endl;
}
void Deanery::trasnferStudent(const string& studentId, const string& curGroup , const string& newGroup)
{
    Group* curGroup_ptr = findGroup(curGroup);
    Group* newGroup_ptr = findGroup(newGroup);
    if(curGroup_ptr && newGroup_ptr)
    {
        Student* student_ptr = curGroup_ptr->findStudent(studentId);
        if(student_ptr)
        {
            curGroup_ptr->expelStudent(*student_ptr);
            newGroup_ptr->addStudent(*student_ptr);
            student_ptr->setGroup(newGroup_ptr);
        }
        else
        {
            cout << "No such student!" << endl;
        }
    }
    else
    {
        cout <<"No such group(s)!";
    }
}
void Deanery::mountPurge()
{
    size_t numberOfExecuted = 0;
    for(auto& group : groups)
    {
        double boundary = 4;
        for(auto& student : group.students)
        {
            if(student.getAverageMark() < 4)
            {
                group.expelStudent(student);
                numberOfExecuted++;
            }
        }
    }
    cout << numberOfExecuted << " failure students has been deleted!";
    cout << " May the filthy bloody souls of these unworthy infidels burn in everlasting hellfire!" << endl;
}
void Deanery::saveData(const string fileName)
{
    ofstream out(fileName);
    if (out.is_open())
    {
        for(auto& group : groups)
        {
            for (auto& student : group.students)
            {
                out << student.getId() << ":" << student.getFio() << ":" << student.getGroup();
            }
        }
    }
    else
    {
        cout << "File is undefined";
    }
    out.close();
}
void Deanery::electHeads()
{
    for(auto& group : groups)
    {
        group.electHead();
    }
}

string Deanery::getName() const
{
    return name;
}
size_t Deanery::getNumberOfGroups() const
{
    return groups.size();
}

void Deanery::printDeanery(ostream& out)
{
    for(auto& group : this->groups)
    {
        group.printGroup(out);
    }
}