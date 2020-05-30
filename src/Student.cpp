//
// Created by fiskirton on 10.02.2020.
//

#include "Student.h"

#include <utility>


Student::Student(int id, string fio) {

    this->id = id;
    this->fio = std::move(fio);

}

Student::~Student() {

    group = nullptr;
    marks.clear();

}

void Student::addMark(int mark) {

    marks.push_back(mark);
    setMeanMark();

}

int Student::getId() const {
    return id;
}

double Student::getMeanMark() {
    return mean_mark;
}

const string &Student::getFio() const {
    return fio;
}

Group &Student::getGroup() {
    return *group;
}

const vector<int> &Student::getMarks() {
    return marks;
}

void Student::setMeanMark() {
    mean_mark = mean(marks);
}

void Student::setGroup(Group * grp) {
    Student::group = grp;
}

