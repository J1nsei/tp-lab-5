#include <iostream>
#include "Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
    this->head = nullptr;
}

std::string Group::getTitle() {
    return title;
}

std::string Group::getSpec() {
    return spec;
}

Student *Group::getHead() {
    return head;
}

bool Group::setHead(int id, std::string fio) {
    for (Student *student : students) {
        if (student->getId() == id && student->getFio() == fio) {
            head = student;
            return true;
        }
    }
    return false;
}

bool Group::setHead() {

    if (!students.empty()) {
        int randNumber = rand() % students.size();
        head = students[randNumber];
        return true;
    }
    return false;
}

Student *Group::getStudentById(int id) {
    for (Student *student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::getStudentByFio(std::string fio) {
    for (Student *student : students) {
        if (student->getFio() == fio) {
            return student;
        }
    }
    return nullptr;
}

double Group::getAverageMark() {
    double averageMark = 0;
    for (Student *student: students) {
        averageMark += student->getAverageMark();
    }
    return averageMark / students.size();
}

void Group::addStudent(class Student *student) {
    students.push_back(student);
    student->setGroup(this);
}

void Group::kickStudent(Student *student) {
    kickStudent(student->getId());
}

void Group::kickStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) {
            delete (students[i]);
            students.erase(students.begin() + i);
        }
    }
}

void Group::kickStudent(std::string fio) {
    kickStudent(getStudentByFio(fio)->getId());
}

std::vector<class Student *> Group::getStudents() {
    return students;
}