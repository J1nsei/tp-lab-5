//
// Created by Sergey Baranenkov on 29.01.2020.
//

#ifndef UNTITLED2_DEANERY_H
#define UNTITLED2_DEANERY_H
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Group.h"
using namespace std;

class Dean {
private:
    map<string, Group *> groupNames;
public:
    Dean()= default;
    void createStudents(const string& filename);
    void createGroups(const string& filename);
    void addGrades(unsigned int n);
    void getStatistics();
    void migrateStudent(const string& group_from,unsigned int id, const string& group_to);
    void expelStudents();
    void saveFiles(const string& dean_path,const string& groups_path, const string& students_path);
    void chooseHeadman();
    void showData();
};
vector<string> split(const string& str, char delim);
#endif //UNTITLED2_DEANERY_H
