//
// Created by fiskirton on 10.02.2020.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "helper.h"

using namespace std;

class Student;

class Group {

private:

    string title;
    string spec;
    int group_id;
    double group_mean_mark{0.0};

private:
    vector<Student *> students;
    Student *head{};

private:

    Group(int group_id, string title, string spec);

    ~Group();

private:

    void addStudent(Student *);

    Student * findStudent(int id);

    Student * findStudent(const string &fio);

    void countGroupMean();

    void excludeStudent(Student *);

    void setHead(Student *headman);

public:

    int getGroupId() const;

    double getGroupMeanMark();

    const string &getTitle() const;

    const string &getSpec() const;

    const vector<Student *> &getStudents() const;

    const Student &getHead() const;

    friend class Deanery;


};

#endif //TASK1_GROUP_H
