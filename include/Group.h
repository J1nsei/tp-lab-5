//
// Created by aklen on 28.01.2020.
//
#include <iostream>
#include <string>
#include <Student.h>
using namespace std;

class Group{
private:
    string title;
    string spec;
    vector<Student*> students;
    Student* head;

public:
    explicit Group(string);
    bool addStudent(Student* );
    void newHead();
    bool searchStudent(int);
    int getAverageGroupMark();
    bool deleteStudent(Student*);
    string getHead();
    string getTitle();

    friend bool Student::joinToGroup(Group *);
    friend class Deanery;
};
