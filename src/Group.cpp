//
// Created by Илья Соловьёв on 15.01.2020.
//

#include "Group.h"
#include "Student.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
}

void Group::addStudent(Student *student) {
    this->students.push_back(student);
}

int Group::getNumberStudents(){
    return students.size();
}

void Group::newHead() {
    this->head = NULL;
    int max = -1;
    for (int i = 0; i < this->students.size(); i++) {
        if (students[i]->calculateAveregeMark() > max) {
            max = students[i]->calculateAveregeMark();
            this->head = students[i];
        }
    }
}

Student *Group::findFIO(std::string fio) {
    for (int i = 0; i < this->students.size(); i++) {
        if (students[i]->fio == fio) {
            return students[i];
        }
    }
    return NULL;
}

double Group::averegeGroupMark() {
    double sum = 0;
    double max = -1;
    for (int i = 0; i < this->students.size(); i++) {
        if (students[i]->calculateAveregeMark() > max) {
            sum += students[i]->calculateAveregeMark();
        }
    }
    return sum / students.size();

}

void Group::removeStudent() {

}