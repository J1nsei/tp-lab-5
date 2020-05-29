//
//  Group.hpp
//  Shtanyuk5
//
//  Created by Коля on 17/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp

class Group;

#include <stdio.h>
#include <string>
#include <numeric>
#include "Student.hpp"
#include <random>

class Group {
private:
    std::string title;
    std::string spec;
    Student *head;
    std::vector<Student*> students;

public:
    Group(std::string, std::string);
    bool addStudent(Student*);
    Student* randHead();
    float getMean();
    std::string getTitle();
    Student* searchStudent(id_t);
    Student* searchStudent(std::string);
    void removeFromGroup(id_t);
};

#endif /* Group_hpp */
