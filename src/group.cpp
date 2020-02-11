//
// Created by Mary on 18.01.2020.
//
#include <iostream>
#include <group.h>

using namespace std;
Group::Group(string title, string spec){
    this->title = string(title, 0, title.size());
    this->spec = string(spec, 0, spec.size());
}

void Group::printStudents() {
    cout << this->title << endl;
    for (auto student : this->students){
        cout << "---------------\n";
        cout << "fio : " << student->getFio() << endl;
        cout << "id : " << student->getId() << endl;
        if (student->getNumberOfMarks() > 0)
            cout << "avarage mark : " << student->getAverageMark() << endl;
        cout <<"----------------\n";
    }
}
void Group::setHead(){
    if (this->students.size() != 0){
        int id= rand()% this->students.size();
        this->head = students[id];
    }
}
void Group::addStudent(Student* student) {
    this->students.push_back(student);
    student->setGroup(this);
}
Student* Group::findStudentByFio(string fio) {
    for (auto i = 0; i < this->students.size(); i ++){
        if (this->students[i]->getFio() == fio){
            return this->students[i];
        }
    }
    return nullptr;
}
Student* Group::findStudentById(int id) {
    for (auto i = 0; i < this->students.size(); i ++){
        if (this->students[i]->getId() == id){
            return this->students[i];
        }
    }
    return nullptr;
}
string Group::getTitle() {
    return  this->title;
}

double Group::getAverageMark() {
    double sum = 0;
    for (auto i = 0; i < this->students.size(); i ++){
        sum += this->students[i]->getAverageMark();
    }
    return (sum / this->students.size());
}

void Group::fireStudent(Student *student) {
    for (auto iter = this->students.begin(); !this->students.empty() && iter != this->students.end(); ++ iter){
        if ((*iter) == student){
            cout << (*iter)->getFio() << " is fired" << endl;
            iter = this->students.erase(iter);
            iter --;
            return;
        }
    }
}

Student* Group::getHead() {
    return this->head;
}