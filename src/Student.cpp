//
// Created by Sergey Baranenkov on 22.01.2020.
//
#include "Group.h"
#include "Student.h"

Student::Student(unsigned int id, string full_name){
    this->id = id;
    this->full_name = std::move(full_name);
}

void Student::add_to_group(Group* _group){
    _group->students.push_back(this);
}

void Student::add_mark(unsigned int mark){
    this->marks.push_back(mark);
}
float Student::get_mean(){
    float sum = 0;
    for (auto mark : marks){
        sum+=mark;
    }
    if (marks.empty()) return 0;
    return sum/marks.size();
}
