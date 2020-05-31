//
//  Student.cpp
//  Shtanyuk5
//
//  Created by Коля on 17/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include "Student.hpp"


std::vector<std::string> split(std::string str, std::string sep)
{
    std::vector<std::string> res;

    size_t pos = str.find(sep);
    while (pos != std::string::npos)
    {
        std::string temp = str.substr(0, pos);
        res.push_back(temp);
        str = str.substr(pos + 1);
        pos = str.find(sep);
    }
    res.push_back(str);
    return res;
}

Student::Student(std::string data, Group* group)
{
    auto arr = split(data, " ");
    this->id = std::stoi(arr[0]);
    this->name = arr[2] + " " + arr[3] + " " + arr[1];
    this->group = group;
}

void Student::addMark(int mark)
{
    this->marks.push_back(mark);
}

float Student::getMean()
{
   return std::accumulate(marks.begin(), marks.end(), 0.0) / marks.size();;
}

void Student::groupEnroll(Group *group)
{
    this->group = group;
}

std::string Student::getName()
{
    return this->name;
}
