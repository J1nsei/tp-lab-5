//
// Created by Sergey Baranenkov on 22.01.2020.
//
#include "Group.h"
#include "Student.h"
Group::Group(const string& group_name){
    this->title = group_name;
}
void Group::add_student(Student* student) {
    this->students.push_back(student);
}
void Group::set_head(Student* student) {
    this->head = student;
}

const Student * Group::find_student(unsigned int find_id) {
    for (auto student : this->students){
        if (student->id == find_id){
            return student;
        }
    }
    return nullptr;
}


float Group::get_average_score(){
    float result = 0;
    for (auto student :students){
        result+=student->get_mean();
    }
    if (students.empty()) return 0;
    return result/students.size();
}

Student* Group::kick_student(unsigned int tokick_id) {
    unsigned int i = 0;
    for (auto it = students.begin();it!=students.end();++it){
        if (students[i]->id == tokick_id){
            if (head == students[i]){
                head = nullptr;
            }
            auto student = students[i];
            students.erase(students.begin() + i);
            return student;
        }
        ++i;
    }
    return nullptr;
}
