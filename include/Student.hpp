//
//  Student.hpp
//  Shtanyuk5
//
//  Created by Коля on 17/02/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp
class Student;

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>  
#include <sstream>
#include "Group.hpp"



class Student
{
private:
    std::string name;
    std::vector<int> marks;
    int id;
    Group *group;
public:
    Student(std::string, Group*);
    ~Student();
    void groupEnroll(Group*);
    void addMark(int);
    float getMean();
    id_t getId() {return id;}
    std::string getName();
};

#endif /* Student_hpp */
