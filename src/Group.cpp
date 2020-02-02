#include "Group.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>


Group::Group(string title, string spec) {
    this->title = title;
    this->spec = spec;
}

Group::~Group() {

}

void Group::addStudent(Student student) {
    students.push_back(student);
}

void Group::takeHead() {
    srand(static_cast<unsigned int>(time(0)));
    head = students[rand() % students.size()];
}

Student Group::searchStudent(int id) {
    for(auto i:students){
        if(i.getId() == id){
            return i;
        }
    }
}

Student Group::searchStudent(string fio) {
    for(auto i:students){
        if(i.getFio() == fio){
            return i;
        }
    }
}

double Group::averageMark() {
    double average = 0;
    for(auto i:students){
        average += i.averageMark();
    }
    return average/students.size();
}

void Group::exclude(int id) {
    Student s = searchStudent(id);
    vector<Student>::iterator it = find(students.begin(), students.end(), s);
    students.erase(it);
}

void Group::exclude(string fio) {
    Student s = searchStudent(fio);
    vector<Student>::iterator it = find(students.begin(), students.end(), s);
    students.erase(it);
}

string Group::getTitle() {
    return title;
}
