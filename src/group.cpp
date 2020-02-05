//
// Created by Mikhail on 16.01.2020.
//

#include <group.h>
#include <numeric>
#include <utility>
#include <algorithm>

Group::Group(string title, string spec) {
    this->title = string(title, 0, title.size());
    this->spec = string(spec, 0, spec.size());
}

void Group::addStudent(Student *student) {
    students.emplace_back(student);
}


void Group::setHead(Student *head) {
    if(!head){
        vector<int> indexes(students.size());
        vector<Student*> students{this->students.begin(), this->students.end()};
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int first, int second){
            pair<int,int> f(0,0), s(0, 0);
            for(auto mark: students[first]->getMarks()){
                if(mark < 3) f.second++;
                else f.first++;
            }
            for(auto mark: students[second]->getMarks()){
                if(mark < 3) s.second++;
                else s.first++;
            }
            return f.first > s.first;
        });
        this->head = students[indexes[0]];
    }
    this->head = head;
}

Student *Group::findStudent(string &FIO) {
    for(auto &student: students){
        if(student->getFIO() == FIO) return student;
    }
    return nullptr;
}

Student *Group::findStudent(int ID) {
    for(auto &student: students){
        if(student->getID() == ID) return student;
    }
    return nullptr;
}

mark_t Group::getMean() {
    size_t numberOfStudents = students.size();
    if(!numberOfStudents) return 0;
    mark_t sum = std::accumulate(
            students.begin(),
            students.end(),
            (mark_t)0,
            [](mark_t was, Student* currentStudent)
            { return was + currentStudent->getMean();}
        );
    return (sum + numberOfStudents / 2) / numberOfStudents;
}

void Group::dropStudent(Student *student) {
    students.remove_if([&](Student* currentStudent){
        return currentStudent == student;
    });
}

list<Student*> Group::getStudents() const{
    return students;
}

string Group::getTitle() const {
    return title;
}

string Group::getSpec()  const {
    return spec;
}