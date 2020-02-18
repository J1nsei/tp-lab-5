#ifndef TASK1_DEANERY_H
#define TASK1_DEANERY_H
#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Group.h"

class Deanery {
private:
    std::string studentFile = "Students.txt";
    std::string groupFile = "Groups.txt";
    std::vector<Group*> groups;
public:
    Deanery();
    ~Deanery();
    void getDataFromFile();
    void addRandomMarkForStudents();
    void showMarksOfStudents();
    void studentTransfer(Student* student, Group* group);
    void kickStudentsWithBadMarks();
    void startHeadElection();
    void showData();
    void saveData();
};


#endif