//
// Created by Mary on 18.01.2020.
//
#include "student.h"
Student::Student(int id, string fio){
    this->id = id;
    this->fio = string(fio, 0, fio.size());
    this->group = nullptr;
}
int Student::getId() {
    return this->id;
}
string Student::getFio() {
    return this->fio;
}
int Student::getNumberOfMarks() {
    return this->marks.size();
}
void Student::setGroup(Group* group) {
    this->group = group;
}
void Student::addMark(int mark) {
    this->marks.push_back(mark);
}
double Student::getAverageMark() {
    double sum = 0;
    for (auto i = 0; i < this->marks.size(); i ++){
        sum += marks[i];
    }
    return sum/this->marks.size();
}
