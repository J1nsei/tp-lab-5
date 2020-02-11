//
// Created by aklen on 01.02.2020.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <Group.h>
using namespace std;

Student::Student(string new_fio) {
    this->fio = new_fio;
    this->id = new_id;
    new_id++;
}


bool Student::joinToGroup(Group *my_group) {
    if (my_group != nullptr){
        if(find(my_group->students.begin(),my_group->students.end(),this) != my_group->students.end())
            return false;
        else {
            this->group = my_group;
            my_group->students.push_back(this);
            return true;
        }
    }
    else{
        this->group = my_group;
        return true;
    }
}


void Student::addMark(int mark) {
    this->marks.push_back(mark);
}


int Student::getAverageMark() {
    int sum = 0;
    for(auto mark: this->marks){
        sum += mark;
    }
    if( this->marks.empty())
        return 0;
    return sum/this->marks.size();

}


int Student::getID() {
    return this->id;
}


string Student::getFio(){
    return this->fio;
}