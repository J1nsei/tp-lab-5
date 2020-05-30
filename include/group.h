#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "student.h"

using namespace std;
class Student;
class Group{
private:
    string title;
    string spec;

    Student* head;
public:
    vector <Student*> students;
    Group(string title, string spec);
    string getTitle();
    void addStudent(Student* student);
    void printStudents();
    void setHead();
    Student* getHead();
    Student* findStudentByFio(string fio);
    Student* findStudentById(int id);
    double getAverageMark();
    void fireStudent(Student* student );
};

#endif //TASK1_GROUP_H