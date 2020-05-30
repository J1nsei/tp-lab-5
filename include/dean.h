#ifndef DEAN_H
#define DEAN_H

#include "group.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;

class Deanery
{
private:
    vector<Group*> groups;
    vector<Student*> students;
    string FileStudents;
    string FileGroups;
    vector<pair<float, string>> studentsStatistics;
    vector<pair<float, string>> groupsStatistics;

public:
    Deanery(string fileStudents, string fileGroups);

    void addStudents();
    void addGroups();
    void setMarks();
    void getStatistics();
    void changeGroup(Student *student, const string& groupTitle);
    void removeStudents();
    void updateData(const string& title_);
    void electHeadmans();
    void printConsole();
    int getStudentsAmount();
};
#endif
