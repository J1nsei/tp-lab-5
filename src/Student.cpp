#include "Student.h"

Student::Student(int id, std::string fio, Group* group) {
    this->id = id;
    this->fio = fio;
    this->group = group;
}

Student::~Student() {
    marks.clear();
}

std::vector<int> Student::getMarks() {
    return marks;
}

int Student::getId() {
    return id;
}

Group *Student::getGroup() {
    return group;
}

std::string Student::getFio() {
    return fio;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

void Student::setGroup(Group *newGroup) {
    group = newGroup;
}

double Student::getAverageMark() {
    double averageMark = 0;
    for (int mark : marks) {
        averageMark += mark;
    }
    return !marks.empty() ? averageMark / marks.size() : 0;
}
