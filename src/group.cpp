#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "group.h"
using namespace std;


Group::Group(string group) {
    this->title = group;
}


bool Group::AddStudent(Student *student) {
    if (find(this->students.begin(),this->students.end(),student) != this->students.end())
        return false;
    this->students.push_back(student);
    student->AddGroup(this);
    return true;
}


void Group::AddHead(){
    this->head = this->students[rand()%students.size()];
}


bool Group::FindStudent(int id) {
    for(auto student: this->students){
        if(student->GetID() == id)
            return true;
    }
    return false;
}


int Group::GetAverageGroupMark() {
    int sum = 0;
    for(auto student: this->students){
        sum += student->GetAverageMark();
    }
    return sum/this->students.size();
}


bool Group::DeleteStudent(Student *student) {
    if(!this->FindStudent(student->GetID()))
        return false;
    student->AddGroup(nullptr);
    int index = 0;
    for(auto current_student: this->students){
        if(student == current_student)
            break;
        index++;
    }
    this->students.erase(this->students.begin() + index);
    return true;
}


string Group::GetHead() {
    return this->head->GetFio();
}

string Group::GetTitle() {
    return this->title;
}