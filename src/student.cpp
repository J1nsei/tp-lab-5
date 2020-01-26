//
// Created by Илья on 026 26.01.20.
//

#include "student.h"


Student::Student(int id, string fio){
    this->id = id;
    this->fio = fio;
}

void Student::addToGroup(Group * group){
    this->group = group;
}

void Student::addMark(int mark){
    this->marks.push_back(mark);
}

double Student::calcAverageMark(){
    int sum = 0;
    for(int mark : marks){
        sum += mark;
    }
    return (double)sum / marks.size();
}