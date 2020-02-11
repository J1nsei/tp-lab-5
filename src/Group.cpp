//
// Created by aklen on 01.02.2020.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <Group.h>
using namespace std;


Group::Group(string group) {
    this->title = group;
}


bool Group::addStudent(Student *student) {
    if (find(this->students.begin(),this->students.end(),student) != this->students.end())
        return false;
    this->students.push_back(student);
    student->joinToGroup(this);
    return true;
}


void Group::newHead(){
    this->head = this->students[rand()%students.size()];
}


bool Group::searchStudent(int id) {
    for(auto student: this->students){
        if(student->getID() == id)
            return true;
    }
    return false;
}


int Group::getAverageGroupMark() {
    int sum = 0;
    for(auto student: this->students){
        sum += student->getAverageMark();
    }
    return sum/this->students.size();
}


bool Group::deleteStudent(Student *student) {
    if(!this->searchStudent(student->getID()))
        return false;
    student->joinToGroup(nullptr);
    int index = 0;
    for(auto current_student: this->students){
        if(student == current_student)
            break;
        index++;
    }
    this->students.erase(this->students.begin() + index);
    return true;
}


string Group::getHead() {
    return this->head->getFio();
}

string Group::getTitle() {
    return this->title;
}