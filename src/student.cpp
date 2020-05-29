//
// Created by Mikhail on 16.01.2020.
//

#include <student.h>
#include <numeric>

Student::Student(int ID, string FIO) {
    this->ID = ID;
    this->FIO = string(FIO, 0, FIO.size());
}

void Student::setGroup(Group *group) {
    this->group = group;
}

void Student::addMark(mark_t mark) {
    marks.emplace_back(mark);
}

mark_t Student::getMean() const {
    if(marks.empty()) return 0;
    mark_t sum = std::accumulate(marks.begin(), marks.end(), (mark_t)0);
    size_t size = marks.size();
    return (sum + size / 2) / size;
}

const string & Student::getFIO() const {
    return this->FIO;
}

int Student::getID() const {
    return ID;
}

Group * Student::getGroup(){
    return group;
}

vector<mark_t> Student::getMarks() const {
    return marks;
}


