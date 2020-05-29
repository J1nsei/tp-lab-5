//
// Created by Mikhail on 22.01.2020.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <iostream>
#include <list>


#include <student.h>


using std::string;
using std::list;
using std::pair;

class Group{
private:
    string title, spec;
    list<Student*> students;
    Student* head{nullptr};
public:
    Group(string title, string spec);
    void addStudent(Student* student);
    void setHead(Student* head = nullptr);
    Student* findStudent(string& FIO);
    Student* findStudent(int ID);
    mark_t getMean();
    void dropStudent(Student* student);
    list<Student*> getStudents() const;
    string getTitle() const;
    string getSpec() const;
};
#endif //TASK1_GROUP_H
