#include "Student.h"

Student::Student(int id, std::string fio){
    this->id = id;
    this->fio = fio;
}

void Student::addToGroup(Group* group){
    this->group = group;
}

void Student::addMark(int mark){
    this->marks.push_back(mark);
}

float Student::getAverageMark(){
    float sum = 0;
    for (auto i = 0; i < this->marks.size(); i++){
        sum += this->marks.at(i);
    }
    return sum/this->marks.size();
}

int Student::getID(){
    return this->id;
}

std::string Student::getFIO(){
    return this->fio;
}

Group* Student::getGroup(){
    return this->group;
}

std::vector<int> Student::getMarks(){
    return this->marks;
}
