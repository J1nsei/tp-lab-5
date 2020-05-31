#include "Group.h"
#include "Student.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>


Group::Group(string title, string spec) {
    this->title = title;
    this->spec = spec;
    students = vector<Student*>();
    head = nullptr;
}

Group::~Group() = default;

void Group::addStudent(Student* student) {
    students.push_back(student);
}

void Group::takeHead() {
    srand(static_cast<unsigned int>(time(nullptr)));
    if(!students.empty())
        head = students[rand() % students.size()];
}

Student* Group::searchStudent(int id) {
    for(auto i:students){
        if(i->getId() == id){
            return i;
        }
    }
    return nullptr;
}

Student* Group::searchStudent(string fio) {
    for(auto i:students){
        if(i->getFio() == fio){
            return i;
        }
    }
    return nullptr;
}

double Group::averageMark() {
    double average = 0;
    for(auto i:students){
        average += i->averageMark();
    }
    if (students.size() < 1){
        return 0;
    }
    else{
        return average/students.size();
    }
}

void Group::exclude(int id) {
    Student* s = searchStudent(id);
    auto it = find(students.begin(), students.end(), s);
    students.erase(it);
}

void Group::exclude(string fio) {
    Student* s = searchStudent(std::move(fio));
    auto it = find(students.begin(), students.end(), s);
    students.erase(it);
}

string Group::getTitle() {
    return title;
}

vector<Student*>& Group::getStudents() {
    return students;
}

Student* Group::getHead() {
    return head;
}

string Group::getSpec() {
    return spec;
}



