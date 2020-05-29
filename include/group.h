//
// Created by Илья on 026 26.01.20.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <vector>
#include <string>

using std::string;
using std::vector;

class Student;  // to avoid a recursive reference

class Group{
private:
    string title;
    string spec;
    vector<Student*> students;
    Student* head;
public:
    Group(string title, string spec);
    void addStudent(Student* student);
    void addHead(Student* head);
    Student* findFio(string fio);
    double calcAverageMark();
    void excludeStudent(Student* student);
    string getTitle();
    string getSpec();
    vector<Student*>& getStudents();
    Student* getHead();
};


#endif //TASK1_GROUP_H
