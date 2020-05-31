#include "Student.h"

Student::Student(std::string fio, Group *group, int id) {
    this->id = id;
    this->fio = fio;
    this->group = group;
}

Student::~Student() {
    this->marks.clear();
}

int Student::getId() {
    return id;
}

std::string Student::getFio() {
    return fio;
}

Group *Student::getGroup() {
    return group;
}

std::vector<int> Student::getMarks() {
    return marks;
}

double Student::getAverageMark() {
    double averageMark = 0;
    for (int mark : marks) {
        averageMark += mark;
    }
    if (averageMark == 0) {
        return 0;
    } else {
        return (averageMark / marks.size());
    }
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

void Student::setGroup(Group *actualGroup) {
    this->group = actualGroup;
}