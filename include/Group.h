//
// Created by Илья Соловьёв on 15.01.2020.
//

#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H

#include <string>
#include <vector>
#include "Deanery.h"

class Student;
class Deanery;


class Group {

    friend Deanery;

    friend Student;


    std::string title;
    std::string spec;
    std::vector<Student *> students;
    Student *head;

    void newHead();

    void removeStudent();

    void addStudent(Student *student);

public:
    Group(std::string title, std::string spec);

    int getNumberStudents();

    Student *findFIO(std::string fio);

    double averegeGroupMark();
};

#endif //TASK1_GROUP_H

