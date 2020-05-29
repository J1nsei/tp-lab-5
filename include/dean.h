//
// Created by Mikhail on 22.01.2020.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H

#include <vector>
#include <iostream>
#include <utility>

#include <student.h>
#include <group.h>

class Group;
class Student;

using std::vector;
using std::string;
using std::ostream;
using std::pair;

vector<string> split(const string &s, char del = ' ');

template <typename T, char sep = ' '>
ostream& operator<<(ostream &out, vector<T> vec){
    for(auto &x: vec){
        out << x << sep;
    }
    return out;
}

class Dean{
    int id = 0;
    vector<pair<string,string> > groupNames;
    vector<string> studentNames;
    list<Student*> students;
    vector<Group*> groups;
    void generateStudents();
    void generateGroups();
public:
    Dean();
    void addMarks();
    list<Student*> getStudents();
    vector<Group*> getGroups();
    vector<vector<pair<int,int> > > stats();
    void removeStudent(Student* student);
    void migrate(Group* from, Group* to, int ID, string FIO);
    void deduction();
    void pickHeads();
    void printData();
    ~Dean();
};
#endif //TASK1_DEAN_H
