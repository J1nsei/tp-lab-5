//
// Created by Илья on 026 26.01.20.
//

#include "group.h"
#include "Student.h"

Group::Group(string title, string spec){
    this->title = title;
    this->spec = spec;
    students = vector<Student*>();
    head = nullptr;
}


void Group::addStudent(Student* student){
    students.push_back(student);
}


void Group::addHead(Student* head){
    this->head = head;
}


Student* Group::findFio(string fio){
    for(Student* student : students){
        string f = student->getFio();
        if (student->getFio() == fio){
            return student;
        }
    }
    return nullptr;
}


double Group::calcAverageMark(){
    if (students.size() == 0){
        return 0;
    }
    int markSum = 0;
    for(Student* student : students){
        markSum += student->calcAverageMark();
    }
    return (double)markSum / students.size();
}


void Group::excludeStudent(Student* student){
    int student_ind = -1;
    for(int i = 0; i < students.size(); i++){
        if (students[i] == student){
            student_ind = i;
            break;
        }
    }

    if(student_ind != -1){
        students.erase(students.begin() + student_ind);
        student->addToGroup(nullptr);
        delete student;
    }
}


string Group::getTitle() {
    return title;
}


string Group::getSpec() {
    return spec;
}


vector<Student*>& Group::getStudents(){
    return students;
}


Student* Group::getHead(){
    return head;
}