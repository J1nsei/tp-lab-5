//
// Created by Оксана on 15.01.2020.
//
#include "Group.h"
#include "Student.h"

using namespace std;

Group::Group(string title, string spec){
    this->title = title;
    this->spec = spec;
}
void Group::Add_student(Student *student){
    students.push_back(student);
}
void Group::Election_of_the_head(Student* head){
    this->head = head;
}
Student* Group::Search_of_student(string fio){
    for(auto student : students){
        if(student->Get_fio() == fio)
            return student;
    }
    return nullptr;
} //поиск студента по ФИО или ИД
Student* Group::Search_of_student(int id){
    for(auto student : students){
        if(student->Get_id() == id)
            return student;
    }
    return nullptr;
}
double  Group::Calc_aver_mark_in_group(){
    double sum = 0;
    for (auto student : students) {
        sum += student->Calc_aver_mark();
    }
    return sum / students.size();
} //вычисление среднего балла в группе
void Group::Exclusion_student(int id){
    int index = 0;
    for (int i = 0; i < students.size(); i++){
        if (students[i]->Get_id() == id){
            index = i;
        }
    }
    students.erase(students.begin() + index);

}
void Group::Exclusion_student(string fio){
    int index = 0;
    for (int i = 0; i < students.size(); i++){
        if (students[i]->Get_fio() == fio){
            index = i;
        }
    }
    students.erase(students.begin() + index);

}
vector<Student*> Group::Get_students() const {
    return students;
}
string Group::Get_title() const {
    return title;
}
string Group::Get_spec() const {
    return spec;
}
Student* Group::Get_head() const {
    return head;
}

unsigned int Group::Get_size() const {
    return students.size();
}
