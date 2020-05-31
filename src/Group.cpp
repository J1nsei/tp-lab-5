#include "Group.h"

Group::Group(std::string title) {
    this->title = title;
}

Group::~Group() = default;

std::string Group::getTitle()  {
    return title;
}

std::string Group::getSpec()  {
    return spec;
}

std::vector<class Student *> Group::getStudents()  {
    return students;
}

Student *Group::getHead()  {
    return head;
}

void Group::addStudent(class Student* student) {
    students.push_back(student);
}

Student *Group::getStudent(int id) {
    for (Student* student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::getStudent(std::string fio) {
    for (Student* student : students) {
        if (student->getFio() == fio) {
            return student;
        }
    }
    return nullptr;
}

void Group::chooseHead() {
    srand(time(nullptr));
    int number = rand() % students.size();
    head = students[number];
}

double Group::getAverageMark() {
    double averageMark = 0;
    for (Student* student : students) {
        averageMark += student->getAverageMark();
    }
    return !students.empty() ? averageMark / students.size() : 0;
}

void Group::kickStudent(Student *student) {
    kickStudent(student->getId());
}

void Group::kickStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) {
            delete (students[i]);
            students.erase(students.begin() + i);
            return;
        }
    }
}

void Group::kickStudent(std::string fio) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getFio() == fio) {
            delete (students[i]);
            students.erase(students.begin() + i);
            return;
        }
    }
}
