//
// Created by Илья on 026 26.01.20.
//

#ifndef TASK1_DEAN_H
#define TASK1_DEAN_H


#include "group.h"

class Deanery{
private:
    vector<Group*> groups;
    int last_id;
public:
    Deanery();
    ~Deanery();
    void createGroup(string, string);
    void addRandomMarks(int);
    void fullStatistics();
    void changeGroup(string, string, string);
    void excludeStudents();
    void saveData(string, string);
    void chooseHeads();
    void printData();
};


#endif //TASK1_DEAN_H
