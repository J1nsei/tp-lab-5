//
// Created by fiskirton on 10.02.2020.
//

#ifndef TASK1_DAENARY_H
#define TASK1_DAENARY_H

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"

using namespace std;

class Group;

class Deanery {

private:

    vector<Group *> groups;

    string students_file_path;
    string groups_file_path;

private:

    void init();

    void refreshData();

    void chooseHeadmen();

public:

    Deanery(const string& students_file_path, const string& groups_file_path);

    ~Deanery();

public:

    void addRandomMarks();

    string getStatistics();

    void transferStudent(int id, const string& dest);

    void excludeStudent(int id);

public:
    const vector<Group *> &getGroups() const;

};

#endif //TASK1_DAENARY_H
