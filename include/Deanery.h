//
// Created by Илья Соловьёв on 15.01.2020.
//

#ifndef TASK1_DEANERY_H
#define TASK1_DEANERY_H

#include <vector>
#include "Student.h"
#include "Group.h"

class Group;

class Deanery {

public:

    int id=0;

    std::vector<Group *> groups;

    Deanery();

    void addMarks();

    void setHead(const std::string& title);

    void getStatistics();

    Group *findGroup(const std::string& title);

    Student *findStudent(const std::string& title);

    void moveStudent(std::string fio, std::string fromGroupTitile, std::string toGroupTitle);

    void cickStudent(std::string fio);

    void addStudent(std::string fio, std::string groupTitle);

    void saveData();

    ~Deanery();

};

#endif //TASK1_DEANERY_H
