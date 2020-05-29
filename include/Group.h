#pragma once
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Group
{
private:
    string name;
    string spec;
    Student head;
    vector<Student> students;
    Student electHead();
    void addStudent(Student student);
    void expelStudent(Student student);
public:
    Group(string title, string spec);
    Student* findStudent(uint32_t id);
    Student* findStudent(string fio);

    double computeAverageMark() const;
    string getName() const;
    string getSpec() const;
    Student getHead() const;
    size_t getSize() const;

    friend class Deanery;
    void printGroup(ostream& out) const;
};
