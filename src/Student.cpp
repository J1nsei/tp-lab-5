//
// Created by Оксана on 15.01.2020.
//

#include"Student.h"
Student::Student(){
    this->id = -1;
    this->fio = "";
}

Student::Student(unsigned int id, string fio){
    this->id = id;
    this->fio = fio;
}

void Student::Set_group(Group *group) {
    this->group = group;
}

void Set_mark(unsigned int){

}

void Student::Add_mark(unsigned int mark){
    marks.push_back(mark);
};
double Student::Calc_aver_mark(){
    int sum = 0;
    for (int x : marks){
        sum += x;
    }
    return sum / marks.size();
}

string Student::Get_fio() const {
    return this->fio;
}

int Student::Get_id() const{
    return this->id;
}

Group* Student::Get_Group() const{
    return this->group;
}
vector<unsigned int> Student::Get_marks() const{
    return this->marks;
}
