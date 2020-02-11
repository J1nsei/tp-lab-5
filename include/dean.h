//
// Created by Mary on 22.01.2020.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H

#include "group.h"
#include "student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
static const vector<string> spec = {"cs_se_", "cs_fm_", "econ_", "cs_bi_"};
class Dean{
private:
    std::vector<Group *> groups;
public:
    void generateStudents();
    void createGroups();
    void addMarks(int num);
    void getStatistics();
    void transferStusents(Student*, Group*);
    void deleteStudent();
    void fireStudents();
    void saveData();
    void setHeads();
    void printData();
    void printStudents();


};

#endif //TASK1_DEAN_H
