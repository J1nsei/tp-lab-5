//
// Created by Илья on 026 26.01.20.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H


#include "group.h"

class Deanery{
private:
    vector<Group*> groups;
public:
    Deanery(string filename); // make students, make groups
    void addRandomMarks();
    void fullStatistics();
    void changeGroup(int id, string title, string spec);
    void excludeStudents();
    void saveData();
    void choose();
    void printData();
};


#endif //TASK1_DEAN_H
