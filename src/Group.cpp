//
//  Group.cpp
//  Shtanyuk5
//
//  Created by Коля on 17/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include "Group.hpp"


Group::Group(std::string title, std::string spec)
{
    this->title = title;
    this->spec = spec;
    this->students.clear();
    this->head = NULL;
}

Student* Group::searchStudent(id_t id)
{
    for (auto st : students)
        if (st->getId() == id)
            return st;
    return NULL;
}

Student* Group::searchStudent(std::string fio)
{
      for (auto st : students)
          if (fio == st->getName())
              return st;
      return NULL;
}

bool Group::addStudent(Student* student)
{
    if (this->searchStudent(student->getId()) != NULL)
        return false;
    this->students.push_back(student);
    return true;
}

void Group::removeFromGroup(id_t id)
{
    if (id < 0 || id >= this->students.size())
         return;
    auto s = this->students[id];
    this->students.erase(this->students.begin()+id);
    if (head == s)
        this->randHead();
}

float Group::getMean()
{
    unsigned long a = 0;
    for (auto student : students)
        a += student->getMean();
    return float(a / students.size());
}

Student* Group::randHead()
{
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(0, int(students.size()));
    auto r = uniform_dist(e1);
    this->head = students[r];
    return students[r];
}

std::string Group::getTitle()
{
    return this->title;
}
