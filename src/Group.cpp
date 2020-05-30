//
// Created by fiskirton on 10.02.2020.
//

#include "Group.h"

#include <algorithm>
#include <utility>

Group::Group(int group_id, string title, string spec) {

    this->group_id = group_id;
    this->title = std::move(title);
    this->spec = std::move(spec);

}

Group::~Group() {

    head = nullptr;

    for (auto student: students){
        delete student;
    }

    students.clear();

}

void Group::addStudent(Student * stdnt) {
    students.push_back(stdnt);
    countGroupMean();
}

Student * Group::findStudent(int id) {

    for (auto student: students){

        if (student->getId() == id){
            return student;
        }
    }

    return nullptr;
}

Student * Group::findStudent(const string &fio){

    for (auto student: students){

        if (student->getFio() == fio){
            return student;
        }
    }

    return nullptr;

}

void Group::countGroupMean() {
//тест: если нет оценок
    vector<double> mean_marks;
    for (auto student: students){
        mean_marks.push_back(student->getMeanMark());
    }

    group_mean_mark = mean(mean_marks);

}

void Group::excludeStudent(Student * student) {
//тест: длинна вектора -1

    students.erase(std::remove(students.begin(), students.end(), student), students.end());


    if (student == head){

        head = students[0];

    }

    countGroupMean();

}

const string &Group::getTitle() const {
    return title;
}

const string &Group::getSpec() const {
    return spec;
}

const vector<Student *> &Group::getStudents() const {
    return students;
}

const Student &Group::getHead() const {
    return *head;
}

int Group::getGroupId() const {
    return group_id;
}

double Group::getGroupMeanMark(){
    return group_mean_mark;
}

void Group::setHead(Student *headman) {
    Group::head = headman;
}
