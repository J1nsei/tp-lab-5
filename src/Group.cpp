//
// Created by Anton Korkunov on 22/01/2020.
//
#include "Group.h"
#include <random>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Group::Group(){
    name="empty";
    spec="empty";
    head=NULL;
};
void Group::create(string _title,string _spec){
   name=_title;
   spec=_spec;
};
void Group::addstud(Student* pupil){
     pupil->ingroup(this);
     students.push_back(pupil);
     //pupil->ingroup(this); adress cur
};
void Group::chHead(){
    int i = rand() % students.size();
    head = students[i];
};
bool Group::findS(const string _name){
    for (int i=0;i<students.size();i++){
     if(_name==students[i]->getName()){
         delStud(i);// for swap function in deanery cpp
         return true;
     }
    }
    return false;
};
double Group::cntBall(){
    int tmpSum=0;
    for (int i=0;i<students.size();i++){
        tmpSum+=students[i]->countAve();
    }
    return tmpSum/students.size();
};
void Group::delStud(int i){
     students.erase(students.begin()+i);
};

void Group::giveMarks(){
    for (int i=0;i<students.size();i++){
        students[i]->addmark();
    }
}
void Group::drop(double aver){
    int tmpSum=0;
    for (int i=0;i<students.size();i++){
        double a = students[i]->countAve();
        if(a < aver){
            delStud(i);
        }
    }
}
string Group::getName(){
    return name;
}

string Group::WriteStudents() {
    string tmpSTR;
    for (int i = 0; i < students.size(); i++) {
        if(students[i]==head)  tmpSTR = tmpSTR + students[i]->getName() + " - староста, средний балл - " + to_string(students[i]->countAve())+"\n";
        else  tmpSTR = tmpSTR + students[i]->getName() + ", средний балл - " + to_string(students[i]->countAve())+"\n";
    }
    return tmpSTR;
}