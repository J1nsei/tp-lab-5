#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "group.h"
using namespace std;

Student::Student(string studentFio) {
    this->fio = studentFio;
    this->id = generatorId;
    generatorId++;
}


bool Student::AddGroup(Group *my_group) {
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


void Student::AddMark(int mark) {
    this->marks.push_back(mark);
}


int Student::GetAverageMark() {
    int sum = 0;
    for(auto mark: this->marks){
        sum += mark;
    }
    if( this->marks.empty())
        return 0;
    return sum/this->marks.size();

}


int Student::GetID() {
    return this->id;
}


string Student::GetFio(){
    return this->fio;
}