//
// Created by Mary on 18.01.2020.
//
#include "dean.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

void Dean::generateStudents() {
    string path = "..\\res\\students.txt";
    vector <Student*> students;
    ifstream stream_from(path);
    string input;
    stringstream in(path);
    int id = 0;
    while (getline(stream_from, input)){
        id ++;
        Student* new_student = new Student(id, input);
        students.push_back(new_student);
    }
    stream_from.close();
    for (int i = 0; i < students.size(); i ++){
        groups[i % 4]->addStudent(students[i]);
    }
}

void Dean::createGroups() {
    for (auto i = 0; i < 4; i ++){
        char num = '1' + i;
        this->groups.push_back(new Group(string(spec[i]) + num, string(spec[i])));
    }
}
void Dean::printStudents(){
    for (int i = 0; i < this->groups.size(); i ++){
        this->groups[i]->printStudents();
    }
}

void Dean::addMarks(int num) {
    for (auto group : groups) {
        for (auto student : group->students) {
            for (int i = 0; i < num; i++) {
                student->addMark(static_cast<unsigned char>(rand() % 10) + 1);
            }
        }
    }
}


void Dean::getStatistics() {
    cout << "-------------Group Statictic--------------\n";
    for (auto group : this->groups){
        cout << group->getTitle() << ": " << group->getAverageMark() << endl;

    }
}

void Dean::transferStusents(Student* student, Group* newGroup) {
    for (auto group : this->groups){
        group->fireStudent(student);
    }
    newGroup->addStudent(student);
}

void Dean::setHeads(){
    for (auto group : this->groups){
        group->setHead();
    }
}

void Dean::fireStudents() {
    for (auto group : this->groups){
        for (auto student : group->students){
            if (student->getAverageMark() < 3.5){
                group->fireStudent(student);
            }
        }
    }

}


