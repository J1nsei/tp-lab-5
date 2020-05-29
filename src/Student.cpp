//
// Created by Anton Korkunov on 16/01/2020.
//

#include "Student.h"
#include <random>
#include <iostream>

using namespace std;

//int nowid=0;

Student::Student(){
   id=-1;
   group=NULL;
   name="empty";

}
void Student::create(string _name, int nowid){
     name=_name;
     id = nowid;
}
void Student::ingroup(Group * _group){
    group=_group;
}
void Student::addmark(){
    int x = rand() % 11;
    marks.push_back(x);
   // std::cout <<x<< std::endl;
}
double Student::countAve(){
    double tmpSred=0;
    for (int i=0;i<marks.size();i++){
        tmpSred+=marks[i];

    }
   // std::cout <<tmpSred/marks.size()<< std::endl;
    return tmpSred/marks.size();
}
string Student::getName(){
    return name;
}
Group * Student::getGroup(){
    return group;
}

int Student::getMarkssize(){
    return marks.size();
};