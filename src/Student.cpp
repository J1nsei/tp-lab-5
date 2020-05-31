#include "Student.h"

Student::Student(int id, string fio) {
    this->id = id;
    this->fio = fio;
}

Student::~Student() {

}

void Student::setGroup(Group* g) {
    this->g = g;
}

void Student::setMarks(vector<int> &marks) {
    for (auto i:marks){
        this->marks[i] = marks[i];
    }
}

int Student::getId() {
    return id;
}

string Student::getFio() {
    return fio;
}

double Student::averageMark() {
    int average = 0;
    for (auto i:marks){
        average += i;
    }
    if (marks.size() < 1){
        return 0;
    }
    else{
        return average/marks.size();
    }
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}


